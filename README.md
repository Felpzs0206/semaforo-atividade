# Projeto de Semáforo com Raspberry Pi Pico

Este projeto simula um semáforo utilizando um Raspberry Pi Pico e três LEDs (vermelho, amarelo e verde). O código foi desenvolvido utilizando o Pico SDK e a função add_repeating_timer_ms() para controlar a temporização das mudanças de estado do semáforo.

## Funcionamento

O semáforo alterna entre os estados vermelho, amarelo e verde a cada 3 segundos. A lógica de controle é implementada utilizando um timer repetitivo que chama uma função de callback a cada segundo.

### Estados do Semáforo

1. **Vermelho**: LED vermelho aceso por 3 segundos.
2. **Amarelo**: LED amarelo aceso por 3 segundos.
3. **Verde**: LED verde aceso por 3 segundos.

Após cada ciclo, o semáforo retorna ao estado inicial (vermelho).

## Código

O código-fonte do projeto está disponível no arquivo semaforo-atividade.c. Ele utiliza a função add_repeating_timer_ms() do Pico SDK para criar um timer que chama a função timer_callback() a cada 1000ms (1 segundo). 
Dentro dessa função, o estado do semáforo é alterado conforme o tempo decorrido.

### Estrutura do Código

- Enumeração dos estados do semáforo (RED, YELLOW, GREEN)
- Função ```timer_callback()```: Controla a lógica de alternância dos LEDs e a mudança de estado.
- Função ```main()```: Inicializa os pinos GPIO, configura o timer e mantém o programa em execução.

## Intruções para Executar

- Clique no arquivo ```diagram.json``` para abrir o circuito no Wokwi.
- clique em "Simular" para iniciar a simulação.

O semáforo começará a funcionar automaticamente, alternando entre os estados vermelho, amarelo e verde a cada 3 segundos.
