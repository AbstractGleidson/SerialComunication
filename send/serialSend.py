import serial
import time
import argparse 

def setArgs() -> argparse.ArgumentParser:
    """
    Mapeia os parâmetos de linha de comando
    Returns:
        argparse.ArgumentParser: Parâmetros de linha de comando
    """
    
    arguments = argparse.ArgumentParser(
        description="Envio de comandos para Arduino via serial"
    )

    # Configura parâmetro para porta
    arguments.add_argument(
        "port",
        type=str,
        help="Porta serial (ex: COM7)"
    )

    # Configura parâmetro de baudrate
    arguments.add_argument(
        "baud",
        type=int,
        help="Taxa de transmissão de dados, baudrate"
    )

    return arguments

if __name__ == "__main__":
    
    args = setArgs().parse_args() # pega os argumentos passados por linha de comando 

    connection = serial.Serial(
        port=args.port, # Porta Serial
        baudrate=args.baud, # Taxa de transmição
        timeout=1
    )

    time.sleep(2)  # tempo para o Arduino reiniciar

    while True:
        
        print("=" * 40)
        print("Digite um comando para enviar via Serial.")
        print("Digite 'S' para sair.")
        command = input("Comando: ")
        
        if len(command) != 1:
            print("Digite apenas um comando por vez!")
        
        elif (command.lower() == 's'):
            print("Encerrando.")
            break
        
        else:
            connection.write(
                command.encode() # converte o caracter em bytes
            ) # Envia para a porta selecionada
        
        print("=" * 40 + "\n\n")

    connection.close() # Fecha a porta