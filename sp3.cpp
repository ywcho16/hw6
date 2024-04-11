#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream xx("my.wav", ios::binary | ios::in);
	if (!xx) return 999;  // if the file is not found
	char header[44];
	// Sprint 1
	xx.read(header, 44);
	xx.close();
	int* sampleRate = (int*)(header + 24);
	cout << "   sampleRate = " << *sampleRate << endl;
	short* n;   n = (short*)(header + 22);  cout << *n << endl; // numChannels
	int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; // sampleRate
	int* b;   b = (int*)(header + 28);  cout << *b << endl;  //  byteRate
	*n = 1;  // mono
	// Sprint 3
	int N = 10 * fs[0];
	short* data;
	data = new short[N];
	const float pi = 3.141592;
	float dt = 1. / fs[0], a = 10000.0, f = 440.0;
	int i = 0;
	ofstream yy("my3.wav", ios::binary | ios::out);
	if (!yy) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
	yy.write(header, 44 * sizeof(char)); // ����� ����. 
	float t = 0;
	for (int j = 0; j < N; j++, t += dt) {
		data[j] = (short)(a * sin(2.0 * pi * f * t));   // a ����, f ���ļ�, N ���ü�(1�ʴ� fs[0] samples, 44100 �Ǵ� 8000)
	}
	yy.write((char*)data, N * sizeof(short));
	yy.close();
	return 1;
}