# 🚗 Sistema de Cadastro de Estacionamento em C

Projeto desenvolvido em linguagem C com foco em prática de lógica de programação, simulando um sistema simples de gerenciamento de dados de
cadastro de veículos em um estacionamento, utilizando manipulação de arquivos `.txt`.

---

##  Funcionalidades

* Criar cadastro de veículo
* Consultar cadastro por placa
* Remover cadastro
* Armazenamento em arquivo (`cadastros.txt`)

---

## Conceitos aplicados

Este projeto utiliza conceitos fundamentais de programação em C:

* Manipulação de arquivos (`fopen`, `fgets`, `fprintf`, `fclose`)
* Strings (`strtok`, `strcmp`, `strcspn`)
* Estruturas (`struct`)
* Controle de fluxo (`while`, `switch`)
* CRUD básico (Create, Read, Delete)

---

## Como funciona

### Cadastro

O usuário insere:

* Nome
* Modelo do carro
* Placa
* Telefone

Os dados são salvos no arquivo `cadastros.txt` e armazenados no formato:

```
Nome;Modelo;Placa;Telefone
```

### Exemplo:

```
Caio;Gol G5;ABC1234;11999999999
Maria;Onix;XYZ9876;11888888888
```

---

### Consulta

* O usuário informa a placa
* O sistema percorre o arquivo linha por linha
* Se encontrar, exibe todas as informações do cadastro

---

### Remoção

* O sistema cria um arquivo temporário
* Copia todos os registros, exceto o que será removido
* Substitui o arquivo original

---

## Como executar

1. Baixe o arquivo `estacionamento.c`

2. Compile o código:

```
gcc estacionamento.c -o estacionamento
```

3. Execute o programa:

```
./estacionamento
```

O arquivo `cadastros.txt` será criado automaticamente na primeira execução, caso ainda não exista.
