#define _CRT_RAND_S
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <iostream>
using namespace std;

// Parameters die je kunt veranderen om queue te testen
// Als alles lijkt te werken, moet je NBOXES maar eens op 1000 zetten en TICK op 10
const int TICK = 10;  // de basis-tijdeenheid in miliseconden
const int NBOXES = 1000; // aantal dozen dat een producent maakt en een consument gebruikt
const int BUFLEN = 4;   // de lengte van de queue

static CRITICAL_SECTION CriticalSectionRead, CriticalSectionWrite;
static HANDLE writeEvent, readEvent;

// Heb mijn eigen random() geschreven
// De standaard rand() geeft voor alle threads dezelfde reeks!
int random(int n)
{
	unsigned int t;
	rand_s(&t);
	return t % n;
}

// Eenvoudig doosje. Niks meer aan doen.
// Bevat alleen de naam van de producent en een volgnummer
class Box
{
private:
	const char *name;
	int number;
public:
	Box(const char *name, int number)
	{
		this->name = name;
		this->number = number;
	}
	// Operator overloading voor de fijnprovers
	friend ostream &operator << (ostream &out, Box *b)
	{
		return out << b->name << "-" << b->number;
	}
};

// De ronde wachtrij
// Die moet je dus thread-safe maken!
class Queue
{
private:
	Box *buffer[BUFLEN];

	// Twee indexen en de lengte bijhouden.
	// Redundant, maar lekker makkelijk!
	int getpos, putpos;
	int count;

public:
	Queue()
	{
		getpos = 0;
		putpos = 0;
		count = 0;
		for (int i = 0; i < BUFLEN; i++) buffer[i] = 0;
	}

	Box *get(const char *consumername)
	{
		EnterCriticalSection(&CriticalSectionRead);
		while (count == 0)
			WaitForSingleObject(writeEvent, INFINITE);

		Box *box = buffer[getpos];
		getpos = (getpos + 1) % BUFLEN;
		count--;
		cout << consumername << ": gets " << box << endl;

		SetEvent(readEvent);
		LeaveCriticalSection(&CriticalSectionRead);
		return box;
	}

	void put(const char *producername, Box *box)
	{
		EnterCriticalSection(&CriticalSectionWrite);
		while (count == BUFLEN)
			WaitForSingleObject(readEvent, INFINITE);

		cout << producername << ": puts " << box << endl;
		buffer[putpos] = box;
		putpos = (putpos + 1) % BUFLEN;
		count++;

		SetEvent(writeEvent);
		LeaveCriticalSection(&CriticalSectionWrite);
	}

	int getCount(){
		return count;
	}
};

// Fijne globale variabele: de wachtrij
Queue q;

// De code voor de productie-thread
// Hoef je niks aan te doen
DWORD WINAPI produce(void *arg)
{
	char *name = (char*)arg;
	for (int i = 0; i < NBOXES; i++)
	{
		Sleep(random(TICK));
		Box *box = new Box(name, i);
		q.put(name, box);
	}
	return 0;
}

// De code voor de consumptie-thread
// Hoef je niks aan te doen
DWORD WINAPI consume(void *arg)
{
	char *name = (char*)arg;
	for (int i = 0; i < NBOXES; i++)
	{
		Sleep(random(TICK));
		Box *box = q.get(name);
		delete box;
	}
	return 0;
}

// Main is ook al klaar.
// Loopt bijna zeker vast als je de queue niet verbeterd.
int _tmain(int argc, _TCHAR* argv[])
{
	InitializeCriticalSection(&CriticalSectionRead);
	InitializeCriticalSection(&CriticalSectionWrite);

	writeEvent = CreateEvent(0, 0, 0, 0);
	readEvent = CreateEvent(0, 0, 0, 0);

	if (writeEvent == NULL || readEvent == NULL){
		cout << "shit failed" << endl;
	}

	CreateThread(0, 0, produce, "P1", 0, 0);
	CreateThread(0, 0, produce, "P2", 0, 0);
	CreateThread(0, 0, produce, "P3", 0, 0);
	CreateThread(0, 0, produce, "P4", 0, 0);

	CreateThread(0, 0, consume, "C1", 0, 0);
	CreateThread(0, 0, consume, "C2", 0, 0);
	CreateThread(0, 0, consume, "C3", 0, 0);
	CreateThread(0, 0, consume, "C4", 0, 0);

	// Druk op een toets om af te breken...
	cin.get();
	DeleteCriticalSection(&CriticalSectionWrite);
	DeleteCriticalSection(&CriticalSectionRead);
	return 0;
}
