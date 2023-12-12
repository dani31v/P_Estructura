#include "Cajas.h"

int main()
{
	setlocale(LC_ALL, "");

	int opc, numCaja = 0, numTurno = 0, caja;
	string extraido20 = "", extraido25 = "";
	string turno;
	bool bloqueo = false;	// Bandera 'false' si no están bloqueadas las cajas C20 y C25; caja D10 cerrada 

	Cajas C20("C20"), C25("C25"), D10("D10");	// Se crean las 3 colas

	do
	{
		cout << "\n 1 Formar  2 Pagar  3 Mostrar  4 Intercalar  5 Salir: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
			numTurno++;	// Número consecutivo para el turno

			if (bloqueo == true)	// Si YA se presentó el bloqueo, se forman solamente en D10
			{
				turno = "SS" + to_string(numTurno);
				D10.Insertar(turno);
				cout << "\tSe formó el turno " << turno << " en la caja D10" << endl;
				break;
			}
			numCaja = (numCaja + 1) % 2;	// Si NO se ha presentado el bloqueo, decide la caja
											// en que formará al cliente, alternados en cajas C20 y C25

			if (numCaja == 1)
			{
				if (numTurno < 10)			// Genera turno
					turno = "NN0" + to_string(numTurno);
				else
					turno = "NN" + to_string(numTurno);

				C20.Insertar(turno);		// Inserta "turno" en caja C20
				cout << "\tSe formó el turno " << turno << " en la caja C20" << endl;
			}
			if (numCaja == 0)
			{
				if (numTurno < 10)			// Genera turno
					turno = "RR0" + to_string(numTurno);
				else
					turno = "RR" + to_string(numTurno);

				C25.Insertar(turno);		// Inserta "turno" en caja C25
				cout << "\tSe formó el turno " << turno << " en la caja C25" << endl;
			}
			break;
		case 2:
			if (bloqueo == true)	// Si YA se presentó el bloqueo, solo cobran en D10
			{
				turno = D10.Extraer();
				if (turno == "")
					cout << "\tLa caja D10 está vacía. No se atendió a nadie\n" << endl;
				else
					cout << "\tSe atendió el turno " << turno << " en la caja D10\n" << endl;
				break;
			}
					// Si NO se ha presentado el bloqueo, pregunta la caja
					// en que cobrará C20 o C25
			cout << "\n¿Qué caja cobrará?    1 C20     2 C25: ";
			cin >> caja;
			if (caja == 1)
			{
				turno = C20.Extraer();
				if (turno == "")
					cout << "\tLa caja C20 está vacía. No se atendió a nadie\n" << endl;
				else
					cout << "\tSe atendió el turno " << turno << " en la caja C20\n" << endl;
			}
			else
			{
				turno = C25.Extraer();
				if (turno == "")
					cout << "\tLa caja C25 está vacía. No se atendió a nadie\n" << endl;
				else
					cout << "\tSe atendió el turno " << turno << " en la caja C25\n" << endl;
			}
			break;
		case 3:
			C20.Mostrar();
			C25.Mostrar();
			D10.Mostrar();
			break;
		case 4:
			bloqueo = true;		// Bandera indica que se presenta el bloqueo
			do
			{
				extraido20 = C20.Extraer();
				if (extraido20 != "")
					D10.Insertar(extraido20);

				extraido25 = C25.Extraer();
				if (extraido25 != "")
					D10.Insertar(extraido25);

			} while (extraido20 != "" || extraido25 != "");	// Extrae alternados uno por uno, hasta
															// que ambas cajas C20 y C25 están vacías
			cout << "\n\t OK. Se formó caja D10\n" << endl;
			break;
		default:
			break;
		}
	} while (opc < 5);
}