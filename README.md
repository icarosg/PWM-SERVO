# Projeto BitDogLab - Controle de servomotor e LED por PWM

## Descrição do Projeto

Neste projeto, foram utilizados os seguintes componentes conectados à placa BitDogLab:

- **LED BLUE** – Pino conectado à **GPIO 12**
- **Servo Motor** – Controlado via **PWM no GPIO 22**

## Funcionalidades do Projeto

- **Controle do Servo Motor via PWM**: Permite movimentação suave do servo entre 0° e 180°.
- **Ajuste de Brilho do LED via PWM**: O LED BLUE é controlado de forma sincronizada com o servo.

## O que é observado no LED?
O LED muda de brilho de acordo com a posição do servo. Como ambos usam o mesmo pulse_width:

- **Posição 0° (500µs):** LED com brilho mínimo.
- **Posição 90° (1470µs):** LED com brilho médio.
- **Posição 180° (2400µs):** LED com brilho máximo.

## Requisitos do Projeto

1. **Uso de PWM:**
   - Implementação do controle de servo motor com frequência de 50Hz.
   - Controle do brilho do LED por PWM, ajustado de acordo com a posição do servo.

## Status do Projeto

Todas as funcionalidades do projeto foram **implementadas com sucesso** e **todos os requisitos foram atendidos**. O sistema está operando de forma estável e confiável, garantindo um funcionamento preciso e eficiente.

## Como Clonar

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/icarosg/PWM-SERVO.git
   cd PWM-SERVO
   ```

## **Demonstração**

Assista ao vídeo demonstrativo no seguinte link: [Vídeo da solução](https://youtu.be/RaYNkYx26Ik).
