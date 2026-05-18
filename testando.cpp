gerar exercicios de encapsulamento ṕara treinar programação orientada a objetos

Aqui estão exercícios progressivos de encapsulamento em Programação Orientada a Objetos (POO) para praticar. Vou usar exemplos neutros que funcionam bem em linguagens como Java, C#, Python ou PHP.
Exercícios de Encapsulamento — Básico ao Avançado
1. Conta Bancária (Básico)

Crie uma classe ContaBancaria com:

    atributo privado saldo

    método depositar(valor)

    método sacar(valor)

    método getSaldo()

Regras:

    não permitir saque maior que o saldo

    não permitir depósito negativo

Objetivo

Treinar:

    atributos privados

    getters

    validação interna

2. Pessoa

Crie uma classe Pessoa com:

    nome

    idade

Regras:

    idade não pode ser negativa

    nome não pode ser vazio

Crie:

    getters

    setters com validação

Desafio extra

Impedir idade maior que 130.
3. Produto em Estoque

Crie uma classe Produto:

    nome

    preco

    quantidade

Métodos:

    adicionarEstoque(qtd)

    removerEstoque(qtd)

Regras:

    preço deve ser maior que 0

    estoque nunca pode ficar negativo

Objetivo

Controlar acesso aos atributos via métodos.
4. Funcionário com Aumento Salarial

Crie uma classe Funcionario:

    nome

    salário privado

Métodos:

    aumentarSalario(percentual)

    getSalario()

Regras:

    percentual deve ser positivo

    salário nunca pode ser negativo

5. Carro (Intermediário)

Crie uma classe Carro:

    velocidade atual

    ligado/desligado

Métodos:

    ligar()

    desligar()

    acelerar()

    frear()

Regras:

    só acelera ligado

    não pode frear abaixo de 0

    não pode desligar em movimento

Objetivo

Encapsular regras de negócio dentro da classe.
6. Sistema de Login

Crie uma classe Usuario:

    login

    senha privada

Métodos:

    autenticar(senha)

    alterarSenha(senhaAtual, novaSenha)

Regras:

    senha mínima de 8 caracteres

    não permitir acessar senha diretamente

Desafio

Criar validação:

    letra maiúscula

    número

    caractere especial

7. Termômetro

Crie uma classe Termometro:

    temperatura privada

Métodos:

    aumentarTemperatura()

    diminuirTemperatura()

    mostrarTemperatura()

Regras:

    temperatura mínima: -50

    temperatura máxima: 60

8. Aluno e Notas

Crie uma classe Aluno:

    nome

    notas privadas

Métodos:

    adicionarNota()

    calcularMedia()

    verificarAprovacao()

Regras:

    notas entre 0 e 10

Exercício Mais Completo (Nível Projeto)
9. Sistema de Conta Corrente

Crie:
Classe Conta

Atributos privados:

    titular

    saldo

    limite

Métodos:

    sacar()

    depositar()

    transferir()

Regras:

    não permitir saldo negativo além do limite

    transferência inválida deve ser cancelada

Classe Banco

    armazenar várias contas

    buscar conta

    listar contas

Objetivos

Treinar:

    encapsulamento real

    comunicação entre objetos

    proteção de dados

Exercícios Desafiadores
10. Controle de Temperatura de Geladeira

A geladeira possui:

    temperatura interna privada

    porta aberta/fechada

Regras:

    temperatura entre 0 e 10

    se porta aberta → não pode diminuir temperatura

    emitir alerta se temperatura > 8

11. Cofre Digital

Crie um cofre com:

    senha privada

    status aberto/fechado

Métodos:

    abrir()

    fechar()

    trocarSenha()

Regras:

    bloquear após 3 tentativas erradas

Mini Desafio de Refatoração

Pegue esta classe ruim:

class Conta {
    public double saldo;
}

Transforme em:

    atributos privados

    métodos seguros

    validações

    regras de negócio

Perguntas para Revisão

    Por que atributos privados são importantes?

    Qual diferença entre getter/setter e atributo público?

    Encapsulamento serve apenas para esconder dados?

    Onde devem ficar as validações?

    O que acontece se qualquer classe puder alterar um atributo livremente?

Desafio Final

Monte um sistema com:

    Cliente

    Conta

    Cartão

    Transação

Todos os atributos privados e regras protegidas.

Exemplo:

    limite do cartão

    senha

    saldo

    autenticação

#include <iostream>
#include <string>
using namespace std;

class Contabanco{
    private:
        int salvo;

    public:
        void deposito(valor){
            if(saldo > 0){
            return (valor + saldo);
            } else{
                cout>> "invalido" endl;
            }
        }

        void sacar(valor){
            if(valor > saldo){
                cout >> "invalido" endl;
            }else {
                return (valor - saldo);
            }
        }

        void getsaldo(){
            return saldo;
        }
};

class pessoa{
    private:
        
}

