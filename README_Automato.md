# Autômato de Pilha
### Reconhecedor da Linguagem `L = { aⁿ bᵏ cⁿ⁺ᵏ | n ≥ 1, k ≥ 1 }`
*Implementação em C++ com Orientação a Objetos*

---

## 1. Sobre a Linguagem

A linguagem reconhecida por este autômato é:

```
L = { aⁿ bᵏ cⁿ⁺ᵏ  |  n ≥ 1, k ≥ 1 }
```

Uma string pertence à linguagem se satisfaz **todas** as condições abaixo:

- Contém exatamente **n** letras `a` (n ≥ 1)
- Seguidas de exatamente **k** letras `b` (k ≥ 1)
- Seguidas de exatamente **n+k** letras `c`
- A **ordem é obrigatória**: primeiro todos os `a`s, depois todos os `b`s, depois todos os `c`s

### Exemplos

| String | n | k | c esperado | Válida? |
|---|---|---|---|---|
| `abcc` | 1 | 1 | 2 | ✅ Sim |
| `aabccc` | 2 | 1 | 3 | ✅ Sim |
| `abbccc` | 1 | 2 | 3 | ✅ Sim |
| `aaabbbcccccc` | 3 | 3 | 6 | ✅ Sim |
| `aabbc` | 2 | 2 | 1 (faltam c's) | ❌ Não |
| `acbbcc` | — | — | ordem errada | ❌ Não |
| `abc` | 1 | 1 | 1 (falta 1 c) | ❌ Não |

---

## 2. Gramática Formal

A gramática livre de contexto que gera esta linguagem é:

| Componente | Definição |
|---|---|
| Variáveis (V) | { S, A, B } |
| Terminais (T) | { a, b, c, ε } |
| Símbolo inicial | S |
| Produções (P) | S → AB |
| | A → aAc \| ac |
| | B → bBc \| bc |

### Como a gramática gera strings

A variável **A** gera o bloco de `a`s e os primeiros **n** `c`s. A variável **B** gera o bloco de `b`s e os últimos **k** `c`s. Ao concatenar A e B, os `c`s de ambos se unem formando **n+k** `c`s no total.

### Exemplo de derivação para `aabccc` (n=2, k=1)

```
S  =>  AB
   =>  aAcB
   =>  aacB        (A => ac)
   =>  aabcc        (B => bc)

Resultado: a a b c c c  ✅
```

---

## 3. O Autômato de Pilha

### Ideia central

Cada letra `a` ou `b` lida **empilha** um símbolo `A` na pilha. Cada letra `c` lida **desempilha** um símbolo. Se ao final da string a pilha estiver exatamente vazia, a contagem de `c`s era igual a n+k e a string é aceita.

### Estados

| Estado | Nome | Papel |
|---|---|---|
| q0 | Inicial | Lendo os `a`s — só aceita `a` ou `b` |
| q1 | Lendo b's | Após o primeiro `b` — só aceita `b` ou `c` |
| q2 | Lendo c's | Após o primeiro `c` — só aceita `c` |
| q3 | Aceitação | Pilha vazia ao fim da string |
| q4 | Erro | Qualquer transição inválida |

### Tabela de Transições

| Estado | Símbolo | Ação na Pilha | Próximo Estado |
|---|---|---|---|
| q0 | `a` | empilha A | q0 |
| q0 | `b` | empilha A | q1 |
| q0 | `c` | — | q4 (erro) |
| q1 | `b` | empilha A | q1 |
| q1 | `c` | desempilha | q2 |
| q1 | `a` | — | q4 (erro) |
| q2 | `c` | desempilha | q2 |
| q2 | `a` ou `b` | — | q4 (erro) |
| q2 | fim + pilha vazia | — | q3 (aceito) |
| q2 | fim + pilha não vazia | — | q4 (erro) |

---

## 4. Como Compilar e Rodar

### Pré-requisitos

- Windows com **MinGW** instalado (g++ disponível no PATH)
- **VSCode** com a extensão C/C++ da Microsoft

### Passo 1 — Abrir o terminal no VSCode

Com a pasta do projeto aberta no VSCode, abra o terminal integrado:

```
Ctrl + `
```

### Passo 2 — Compilar

No terminal, execute o comando abaixo para compilar todos os arquivos juntos:

```bash
g++ main.cpp Pilha.cpp Automato.cpp -o automato
```

Se não aparecer nenhuma mensagem de erro, a compilação foi bem-sucedida e o arquivo `automato.exe` foi gerado.

### Passo 3 — Executar

```bash
.\automato
```

O programa vai solicitar que você digite uma string e exibirá se ela foi **ACEITA** ou **REJEITADA**.

### Exemplo de execução

```
Digite a string: aabccc
String ACEITA!

Digite a string: aabbc
String REJEITADA!
```

---

## 5. Casos de Teste

| String | Resultado esperado | Motivo |
|---|---|---|
| `abcc` | ✅ ACEITA | n=1, k=1, c=2 |
| `aabccc` | ✅ ACEITA | n=2, k=1, c=3 |
| `abbccc` | ✅ ACEITA | n=1, k=2, c=3 |
| `aaabbbcccccc` | ✅ ACEITA | n=3, k=3, c=6 |
| `aabbc` | ❌ REJEITA | Faltam c's |
| `abc` | ❌ REJEITA | Falta 1 c |
| `acbbcc` | ❌ REJEITA | Ordem errada |
| `cccaabb` | ❌ REJEITA | Começa com c |
| `aabb` | ❌ REJEITA | Sem c's |