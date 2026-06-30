# =============================================================================
# TRABALHO FINAL - ELETRICIDADE BÁSICA - ENGENHARIA DE COMPUTAÇÃO
# Calculadora Inteligente para Análise de Resistências Equivalentes
# em Circuitos Série, Paralelo e Mistos
# =============================================================================

# =============================================================================
# CLASSE: Resistor 
# =============================================================================

class Resistor:
    """Representa um resistor com valor numérico em ohms."""

    def __init__(self, nome: str, valor_ohms: float):
        if valor_ohms <= 0:
            raise ValueError(f"Valor do resistor '{nome}' deve ser maior que zero.")
        self.nome = nome
        self._valor = valor_ohms

    def get_valor(self) -> float:
        return self._valor

    def __str__(self) -> str:
        return f"{self.nome}: {self._valor}Ω"


# =============================================================================
# CLASSE: ResistorCores 
# =============================================================================

class ResistorCores(Resistor):
    """Resistor cujo valor é calculado a partir das faixas de cores."""

    # Atributos de classe — compartilhados por todas as instâncias
    CORES = {
        "preto":    (0, 1),
        "marrom":   (1, 10),
        "vermelho": (2, 100),
        "laranja":  (3, 1_000),
        "amarelo":  (4, 10_000),
        "verde":    (5, 100_000),
        "azul":     (6, 1_000_000),
        "violeta":  (7, 10_000_000),
        "cinza":    (8, 100_000_000),
        "branco":   (9, 1_000_000_000),
    }

    TOLERANCIAS = {
        "ouro":   "±5%",
        "prata":  "±10%",
        "nenhum": "±20%",
    }

    def __init__(self, nome: str, cor1: str, cor2: str, cor_mult: str, cor_tol: str = "nenhum"):
        self._validar_cores(cor1, cor2, cor_mult, cor_tol)
        valor = self._calcular_valor(cor1, cor2, cor_mult)

        super().__init__(nome, valor)  # chama o __init__ da classe mãe

        self._cor1 = cor1
        self._cor2 = cor2
        self._cor_mult = cor_mult
        self._tolerancia = self.TOLERANCIAS[cor_tol]

    def _calcular_valor(self, cor1: str, cor2: str, cor_mult: str) -> float:
        digito1 = self.CORES[cor1][0]
        digito2 = self.CORES[cor2][0]
        multiplicador = self.CORES[cor_mult][1]
        return (digito1 * 10 + digito2) * multiplicador

    def _validar_cores(self, cor1: str, cor2: str, cor_mult: str, cor_tol: str):
        for cor in (cor1, cor2, cor_mult):
            if cor not in self.CORES:
                raise ValueError(f"Cor inválida: '{cor}'. Cores disponíveis: {list(self.CORES.keys())}")
        if cor_tol not in self.TOLERANCIAS:
            raise ValueError(f"Tolerância inválida: '{cor_tol}'. Use: ouro, prata ou nenhum.")

    def __str__(self) -> str:
        return (
            f"{self.nome}: {self._valor}Ω "
            f"[{self._cor1}, {self._cor2}, {self._cor_mult}] "
            f"Tolerância: {self._tolerancia}"
        )


# =============================================================================
# CLASSE: Circuito 
# =============================================================================

class Circuito:
    """Classe base para os circuitos elétricos (série, paralelo, misto)."""

    def __init__(self):
        self._resistores = []

    def adicionar_resistor(self, resistor: Resistor):
        self._resistores.append(resistor)

    def calcular_equivalente(self) -> float:
        raise NotImplementedError("Subclasse deve implementar calcular_equivalente().")

    def relatorio(self) -> str:
        linhas = ["=== Relatório ==="]
        for r in self._resistores:
            linhas.append(f"  {r}")
        linhas.append(f"Req = {self.calcular_equivalente():.2f}Ω")
        return "\n".join(linhas)


# =============================================================================
# CLASSE: CircuitoSerie 
# =============================================================================

class CircuitoSerie(Circuito):
    """Resistores em série: Req = R1 + R2 + ... + Rn"""

    def calcular_equivalente(self) -> float:
        if not self._resistores:
            raise ValueError("Nenhum resistor adicionado ao circuito.")
        return sum(r.get_valor() for r in self._resistores)


# =============================================================================
# CLASSE: CircuitoParalelo 
# =============================================================================

class CircuitoParalelo(Circuito):
    """Resistores em paralelo: 1/Req = 1/R1 + 1/R2 + ... + 1/Rn"""

    def calcular_equivalente(self) -> float:
        if not self._resistores:
            raise ValueError("Nenhum resistor adicionado ao circuito.")
        return 1 / sum(1 / r.get_valor() for r in self._resistores)


# =============================================================================
# CLASSE: CircuitoMisto 
# =============================================================================

class CircuitoMisto(Circuito):
    """
    Circuito misto: grupos em paralelo, ligados em série entre si.

    Exemplo: Grupo1 [R1, R2] em paralelo + Grupo2 [R3] em série
    Req = (R1 // R2) + R3
    """

    def __init__(self):
        self._grupos = []  # lista de listas de resistores

    def adicionar_grupo(self, resistores: list):
        if not resistores:
            raise ValueError("Grupo não pode ser vazio.")
        self._grupos.append(resistores)

    def calcular_equivalente(self) -> float:
        if not self._grupos:
            raise ValueError("Nenhum grupo adicionado ao circuito misto.")

        req_total = 0
        for grupo in self._grupos:
            if len(grupo) == 1:
                req_total += grupo[0].get_valor()
            else:
                req_total += 1 / sum(1 / r.get_valor() for r in grupo)
        return req_total

    def relatorio(self) -> str:
        linhas = ["=== Relatório Circuito Misto ==="]
        for i, grupo in enumerate(self._grupos):
            linhas.append(f"  Grupo {i + 1}:")
            for r in grupo:
                linhas.append(f"    {r}")
        linhas.append(f"Req = {self.calcular_equivalente():.2f}Ω")
        return "\n".join(linhas)


# =============================================================================
# CLASSE: Calculadora 
# =============================================================================

class Calculadora:
    """Controla o fluxo do programa: cadastro -> seleção -> cálculo -> relatório."""

    def __init__(self):
        self._circuito = None

    def executar(self):
        print("=" * 50)
        print("  CALCULADORA DE RESISTÊNCIA EQUIVALENTE")
        print("=" * 50)

        tipo = self._escolher_tipo_circuito()

        if tipo == "misto":
            self._circuito = CircuitoMisto()
            self._montar_circuito_misto()
        else:
            self._circuito = CircuitoSerie() if tipo == "serie" else CircuitoParalelo()
            self._montar_circuito_simples()

        self._mostrar_relatorio()

    def _escolher_tipo_circuito(self) -> str:
        opcoes = {"1": "serie", "2": "paralelo", "3": "misto"}
        print("\nTipo de circuito:")
        print("  1. Série")
        print("  2. Paralelo")
        print("  3. Misto")

        while True:
            escolha = input("Escolha (1-3): ").strip()
            if escolha in opcoes:
                return opcoes[escolha]
            print("Opção inválida. Tente novamente.")

    def _montar_circuito_simples(self):
        contador = 1
        while True:
            print(f"\n--- Resistor R{contador} ---")
            resistor = self._cadastrar_resistor(f"R{contador}")
            if resistor:
                self._circuito.adicionar_resistor(resistor)
                contador += 1

            if contador > 2 and not self._continuar("Adicionar outro resistor?"):
                break

    def _montar_circuito_misto(self):
        grupo_num = 1
        while True:
            print(f"\n=== Grupo {grupo_num} (resistores em paralelo dentro do grupo) ===")
            grupo = []
            contador = 1
            while True:
                print(f"\n--- Resistor do Grupo {grupo_num} (R{contador}) ---")
                resistor = self._cadastrar_resistor(f"G{grupo_num}R{contador}")
                if resistor:
                    grupo.append(resistor)
                    contador += 1

                if not self._continuar("Adicionar outro resistor neste grupo?"):
                    break

            self._circuito.adicionar_grupo(grupo)
            grupo_num += 1

            if not self._continuar("Adicionar outro grupo (em série com os anteriores)?"):
                break

    def _cadastrar_resistor(self, nome_padrao: str) -> Resistor:
        print("Modo de entrada:")
        print("  1. Numérico (digitar valor em Ω)")
        print("  2. Por faixas de cores")
        modo = input("Escolha (1-2): ").strip()

        try:
            if modo == "1":
                valor = float(input(f"Valor de {nome_padrao} (Ω): "))
                return Resistor(nome_padrao, valor)

            elif modo == "2":
                print(f"Cores disponíveis: {list(ResistorCores.CORES.keys())}")
                cor1 = input("Faixa 1: ").strip().lower()
                cor2 = input("Faixa 2: ").strip().lower()
                cor_mult = input("Faixa 3 (multiplicador): ").strip().lower()
                cor_tol = input("Faixa 4 (tolerância: ouro/prata/nenhum) [nenhum]: ").strip().lower() or "nenhum"
                return ResistorCores(nome_padrao, cor1, cor2, cor_mult, cor_tol)

            else:
                print("Opção inválida. Resistor não adicionado.")
                return None

        except ValueError as e:
            print(f"Erro: {e}. Resistor não adicionado.")
            return None

    def _continuar(self, pergunta: str) -> bool:
        resposta = input(f"{pergunta} (s/n): ").strip().lower()
        return resposta == "s"

    def _mostrar_relatorio(self):
        print("\n" + "=" * 50)
        try:
            print(self._circuito.relatorio())
        except ValueError as e:
            print(f"Erro: {e}")
        print("=" * 50)


# =============================================================================
# PONTO DE ENTRADA
# =============================================================================

if __name__ == "__main__":
    calculadora = Calculadora()
    calculadora.executar()
