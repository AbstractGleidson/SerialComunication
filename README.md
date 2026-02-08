# Comunicação Serial

Projeto simples para testar a comunicação serial via USB entre um **Notebook** e um **Arduino Mega**, utilizando um **display de 7 segmentos** como saída.

O Notebook envia um caractere pela porta serial e o Arduino exibe o valor correspondente no display.

---

## Comunicação

- Tipo: Serial USB
- Sentido: Unilateral (Notebook -> Arduino)
- Dados: 1 caractere (ASCII)

---

## Hardware

- Arduino Mega
- Display de 7 segmentos
- Resistores em todos os segmentos

---

## Funcionamento

- O Arduino lê o primeiro caractere recebido pela Serial
- Se for `'0'` a `'9'`, exibe o número no display
- Caso contrário, exibe **E** (erro)

---

## Execução

### Arduino
- Compile e envie o código para o Arduino Mega

### Python
```bash
python serialSend.py port baud
```

- ``port``: Porta na qual está conectado o arduino.
- ``baud``: taxa de trasmição de dados (baudrate).
