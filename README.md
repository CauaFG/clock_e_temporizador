# Semáforo temporizado

## Descrição do projeto
Este projeto foi feito para a Embarcatech. Ele implementa um semáforo simples utilizando o microcontrolador Raspberry Pi Pico W, com LEDs representando os sinais vermelho, amarelo e verde.

## Funcionalidades
- Ciclo de semáforo com temporização de 3 segundos por sinal (vermelho, amarelo, verde).

- Mensagem impressa na porta serial a cada segundo para indicar o contador de tempo.

- Utiliza os GPIOs 11, 12 e 13 para controlar LEDs vermelho, amarelo e verde.

## Como utilizar
- Clone o repositório
- No Visual Studio Code, com as extensões do Raspberry Pi Pico W e Wokwi instaladas, importe o projeto para o Raspberry Pi Pico W.
- Compile o arquivo semaforo.c.
- Abra o arquivo diagram.json e comece a executar o projeto.
