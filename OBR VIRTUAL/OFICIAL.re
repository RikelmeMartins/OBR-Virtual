numero kp = 1.4
numero erro = 0
numero saida = 0

tarefa Mover com numero velD, numero velE{
	Motor("motordr", velD)
	Motor("motores", velE)
	Motor("motordrt", velD)
	Motor("motorest", velE)
}

tarefa Frente com numero velocidade = 100{
	TravarMotor("motordr", falso)
	TravarMotor("motores", falso)
	TravarMotor("motordrt", falso)
	TravarMotor("motorest", falso)

	Motor("motordr", velocidade)
	Motor("motores", velocidade)
	Motor("motordrt", velocidade)
	Motor("motorest", velocidade)
}

tarefa Subir com numero velocidade = 600{
	Motor("motordr", velocidade)
	Motor("motores", velocidade)
}

tarefa Tras com numero velocidade = 90{
	Motor("motordr", 0-velocidade)
	Motor("motores", 0-velocidade)
	Motor("motordrt", 0-velocidade)
	Motor("motorest", 0-velocidade)
}

tarefa TrasD com numero velocidade = 150{
	Motor("motordr", 0-velocidade)
	Motor("motores", 0-velocidade)
	Motor("motordrt", 0-velocidade)
	Motor("motorest", 0-velocidade)
}


tarefa Direita com numero velocidade = 300{
	TravarMotor("motordr", falso)
	TravarMotor("motores", falso)
	TravarMotor("motordrt", falso)
	TravarMotor("motorest", falso)

	Motor("motordr", 0-velocidade)
	Motor("motores", velocidade)
	Motor("motordrt", 0-velocidade)
	Motor("motorest", velocidade)
}

tarefa Esquerda com numero velocidade = 500{ 
	Motor("motordr", velocidade)
	Motor("motores", 0-velocidade)
	Motor("motordrt", velocidade)
	Motor("motorest", 0-velocidade)
}

tarefa DireitaC com numero velocidade = 200{
	Motor("motordr", 0-velocidade)
	Motor("motores", velocidade)
	Motor("motordrt", 0-velocidade)
	Motor("motorest", velocidade)
}

tarefa EsquerdaC com numero velocidade = 300{ 
	Motor("motordr", velocidade)
	Motor("motores", 0-velocidade)
	Motor("motordrt", velocidade)
	Motor("motorest", 0-velocidade)
}
 
tarefa Parar { 
	TravarMotor("motordr", verdadeiro)
	TravarMotor("motores", verdadeiro)
	TravarMotor("motordrt", verdadeiro)
	TravarMotor("motorest", verdadeiro)
}


tarefa PortaT com numero velocidade = 50{
	TravarMotor("motorL", falso)
	Motor("motorL", 0-velocidade)
}

tarefa Garra com numero velocidade = 200{
	TravarMotor("motorg1", falso)
	Motor("motorg1", 0-velocidade)
}

tarefa GarraB com numero velocidade = 200{
	TravarMotor("motorg1", falso)
	Motor("motorg1", velocidade)
}

tarefa GarraD com numero velocidade = 100{
	TravarMotor("motorg", falso)
	Motor("motorg", 0-velocidade)
}

tarefa GarraL com numero velocidade = 100{
	TravarMotor("motorg", falso)
	Motor("motorg", velocidade)
}

tarefa Levantar com numero velocidade = 100{
	TravarMotor("motorL", falso)
	Motor("motorL", velocidade)
}


tarefa Desvio{
TrasD()
Esperar(1000)
Direita()
Esperar(2100)
Frente()
Esperar(3200)
Esquerda()
Esperar(1100)
Frente()
Esperar(4700)
Esquerda()
Esperar(1300)

enquanto (Cor("sC") != "Preto") farei 
{
Esperar(100)
Frente()
}
enquanto (Cor("dI") != "Preto") farei 
{
	Esperar(100)
	DireitaC()
}

}

inicio

TravarMotor("motordr", falso)
TravarMotor("motores", falso)
TravarMotor("motordrt", falso)
TravarMotor("motorest", falso)

Garra()
Esperar(100)

enquanto (verdadeiro) farei 
{
    Esperar(100)

	#Rampa
	se (Ultra("ultraD") > 2 e Ultra("ultraD") > 0-1 e Ultra("ultraD") < 4) entao
	{
        LigarLuz("LedE", 0, 0, 128)
		erro = Luminosidade("dI") - Luminosidade("eI")
		saida = erro * kp
		Mover((500 + saida), (500 - saida))
        se (Inclinacao() > 0.4 e Inclinacao() < 30) entao #Resgate
        {
            enquanto (verdadeiro) farei 
            {
                Esperar(100)
				LigarLuz("LedE", 255, 0, 128)
				enquanto (Ultra("ultra1") > 8 e Ultra("ultra1") > 0-1) farei
				{
				Esperar(100)
				Frente()
				}
				Parar()
				Esperar(1000)
				Direita()
				Esperar(3000)
                se ((Ultra("ultraEB") <= 3 e Ultra("ultraEB") > 0-1) e (Ultra("ultraEC") < 10 e Ultra("ultraEC") > 0-1)) entao
				{
					AbrirConsole()
					Escrever("Resgate")
					Parar()
					Esperar(1000)
					GarraB()
					Esperar(100)
                }	

            }

        }
	}
    senao se (Ultra("ultra1") <= 2 e Ultra("ultra1") > 0-1) entao #Obstaculo
    {
        LigarLuz("LedD", 255, 0, 0)
		LigarLuz("LedE", 255, 0, 0)
		Desvio()
    }
    senao se ((Inclinacao() >= 340) e (Ultra("ultra1") >= 4 e Ultra("ultra1") < 5 e Ultra("ultra1") > 0-1)) entao
    {
        kp = 7
		enquanto (verdadeiro) farei
		{
			Esperar(100)
			TravarMotor("motorg", verdadeiro)
			TravarMotor("motorg1", verdadeiro)
			erro = Luminosidade("dI") - Luminosidade("eI")
			saida = erro * kp
			Mover((1100 + saida), (1100 - saida))
			se (Inclinacao() > 0.4 e Inclinacao() < 30) entao
			{
				LigarLuz("LedE", 255, 0, 0)
				Interromper()
			}
		}
    }
    senao
    {
        se (Cor("dI") == "Verde" ou Cor("dX") == "Verde") entao
		{
			se (Cor("eI") == "Verde" ou Cor("eX") == "Verde") entao
			{
			LigarLuz("LedD", 0, 255, 0)
			LigarLuz("LedE", 0, 255, 0)
			TrasD()
			Esperar(1000)
			enquanto (Cor("sC") != "Preto") farei 
			{
				Esperar(100)
				Direita()	
			}
			}
		}
		senao se (Cor("dI") == "Preto" e Cor("eI") == "Preto" e Cor("dX") == "Preto" e Cor("eX") == "Preto") entao
		{	
			LigarLuz("LedD", 0, 0, 0)
			LigarLuz("LedE", 0, 0, 0)
			Frente()
			Esperar(1500)
		}
		senao se (Cor("dI") == "Verde" ou Cor("dX") == "Verde") entao 
		{
			Esperar(100)
			LigarLuz("LedD", 0, 255, 0)
			Frente()
			Esperar(400)
			Direita()
			Esperar(1000)
			enquanto(Cor("sC") != "Preto") farei 
			{	
				Esperar(100)
				DireitaC()	
			}
		}
		senao se (Cor("eI") == "Verde" ou Cor("eX") == "Verde") entao 
		{
			Esperar(100)
			LigarLuz("LedE", 0, 255, 0)
			Frente()
			Esperar(400)
			Esquerda()
			Esperar(1000)
			enquanto (Cor("sC") != "Preto") farei
			{
				Esperar(100)
				EsquerdaC()
			}
		} 
		senao se (Cor("dX") == "Preto" e Cor("eX") == "Branco") entao 
		{
			LigarLuz("LedD", 0, 0, 255)
			Frente()
			Esperar(100)
			Direita()
			Esperar(1000)
			enquanto(Cor("sC") != "Preto") farei 
			{	
				Esperar(100)
				DireitaC()	
			}
			TrasD()
			Esperar(250)
		}
		senao se (Cor("eX") == "Preto" e Cor("dX") == "Branco") entao 
		{
			LigarLuz("LedE", 0, 0, 255)
			Frente()
			Esperar(50)
			Esquerda()
			Esperar(1000)
			enquanto(Cor("eI") != "Preto") farei 
			{	
				Esperar(100)
				EsquerdaC()	
			}
			TrasD()
			Esperar(250)
		}
		senao
		{
			Esperar(100)
			erro = Luminosidade("dI") - Luminosidade("eI")
			saida = erro * kp
			Mover((100 + saida), (100 - saida))
		}

    }   
} 
fim