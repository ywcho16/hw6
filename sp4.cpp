//#include <iostream>
//#include <fstream>
//using namespace std;
//
//// �Ǻ� txt���� ���� ������ �ð�, ���ļ�, ���� return�ϴ� �Լ�
//// �ð� return �Լ�
//float getLength(int eum) {
//    return 4. / (float)eum;
//}
//// ���ļ� return �Լ�
//float getfrequency(char hhh, int octa) {
//    int oc_mul = 1;
//    for (int i = 1; i < octa; i++) {
//        oc_mul *= 2;
//    }
//    float mul = oc_mul / 4;
//    if (hhh == 'C') return 130.81 * mul;
//    else if (hhh == 'c') return 138.59 * mul;
//    else if (hhh == 'D') return 146.83 * mul;
//    else if (hhh == 'd') return 155.56 * mul;
//    else if (hhh == 'E') return 164.81 * mul;
//    else if (hhh == 'F') return 174.61 * mul;
//    else if (hhh == 'f') return 185.00 * mul;
//    else if (hhh == 'G') return 196.00 * mul;
//    else if (hhh == 'g') return 207.65 * mul;
//    else if (hhh == 'A') return 220.00 * mul;
//    else if (hhh == 'a') return 233.08 * mul;
//    else if (hhh == 'B') return 246.94 * mul;
//    else {
//        cout << "���谡 �߸��Ǿ����ϴ�." << endl;
//        return 100.;
//    }
//
//}
//// ���� return �Լ�
//float getAmplitude(int sss) {
//    return sss * 1000;
//}
//
//int main() {
//
//    char header[44]; //Memory allocation
//    ifstream myfile("Beatles-LetItBe-wav_30s.wav", ios::in | ios::binary); // 'myfile' ��ü ���� �� binary file�� read mode�� ���� 
//    if (!myfile) { // ���� ������ ������ ������ ������
//        cout << " File not found : " << "Beatles-LetItBe-wav_30s.wav";
//        return 333;
//    }
//    myfile.read(header, 44); // sprint1:'myfile' ���� ��ü���� 44����Ʈ ũ���� �����͸� �о header�迭�� ����
//    short* n;  n = (short*)(header + 22);  cout << *n << endl; //sprint1: ���� cout�ؼ� Ȯ���غ���, NumChannels
//    int* fs;   fs = (int*)(header + 24);  cout << *fs << endl; //SampleRate(1�� ������ �Ҹ��� �� ���� �������� �ɰ��� ����(�м�)�ϴ°�)
//    int* b;    b = (int*)(header + 28);  cout << *b << endl; //ByteRate(1�� ���� �Ҹ��� ���µ� �ʿ��� byte ��)
//    int N = fs[0] * 10;  //Memory allocation, Sprint 2:10�� �з�  
//    short* data;
//
//    const float pi = 3.141592;
//    float dt = 1. / fs[0];
//
//    data = new short[N]; // 'data'������ short�� �����ͷ�, �����Ҵ�� short�迭�� ����Ű�� ������
//    for (int i = 0; i < N; i++) data[i] = 0;
//    *n = 1; // NumOfChannel �ٲٱ� 
//    *b = n[0] * fs[0] * sizeof(short); // byte/sec �ٲٱ�
//    myfile.close();
//
//    ofstream yy("my3.wav", ios::binary | ios::out);  // ofstream�� �̸� yy�� ifstream�� �̸� xx�� �ٸ��� �Ѵ�.
//    if (!yy) return 666;  // ���� ������ ������ ������ ���α׷��� ������. 
//    yy.write((char*)header, 44 * sizeof(char)); // ����� ����.
//    //yy.close();
//
//    // ���䳢�� �Ǻ� txt �����. ����: "�� ��ǥ ��\ù �� ����\n��° �� ����\n��° �� ����\n..."
//    // �� ���� ���: �����ǥ(1, 2, 4, 8, 16, 32) ���� ��ũ��(0~30) ��Ÿ��(1~5)
//    // ���� ����: ���ĺ� �빮�� C, D, E ...
//    // ���� ����: �ݿø����� ����. ���ĺ� �ҹ���. c = C#, a = A#
//    // ȭ��: �����ǥ �ڸ��� 100 ���� �� �ֱ�. �� ���� ���� ���� ���ÿ� ������.
//    ofstream ww("santoki.txt");
//    ww << "19\n4 G 10 4\n8 E 5 4\n8 E 5 4\n8 G 10 4\n8 E 5 4\n4 C 8 4";
//    // ���䳢 ȭ�� �߰� �Ǻ�
//    ww << "\n400 G 10 4\n8 G 10 3\n8 C 10 4\n800 E 5 4\n8 E 10 3\n800 E 5 4\n8 C 10 4\n800 G 10 4\n8 G 10 3\n800 E 5 4\n8 E 10 3\n400 C 8 4\n4 C 10 3";
//    ww.close();
//
//    // ���䳢 �Ǻ� �а� ���ļ�, ����, �ð� �����ϱ�
//    ifstream zz("santoki.txt");
//    if (!zz) return 777;  // ���� ������ ������ ������ ���α׷��� ������. 
//    int count, eu, ss, oc, data_ind = 0;
//    float f, a, T;
//    char hh;
//    bool hwaeum = false;
//    zz >> count; // ��ǥ�� �� ������ �б�
//    for (int i = 0; i < count; i++) {
//        zz >> eu >> hh >> ss >> oc;  // eu: �� ����, hh: ����, ss: �� ũ��, oc: ��Ÿ��
//        f = getfrequency(hh, oc);    // ���ļ��� return �Ǵ� �Լ�
//        a = getAmplitude(ss);    // ������ return�Ǵ� �Լ�
//        T = getLength(eu);       // �ð��� return�Ǵ� �Լ�
//        if (T <= 0.05) { //���� ȭ���� ���Դٸ�
//            T = T * 100;
//            for (int j = 0; j < T * fs[0]; j++) { // �ش� �ð���ŭ a * sin(2*pi*f*t)�� ���ü�(fs[0]*T)��ŭ ����Ͽ� data�� �ֱ�
//                data[data_ind + j] += (short)(a * sin(2.0 * pi * f * j * dt));   // a ����, f ���ļ�, N ���ü�
//                // �׸��� �ε����� �ѱ��� �ʰ� ������ ���� ���� ���̰� �����
//            }
//        }
//        else { //�Ϲ� ���� ���Դٸ�
//            for (int j = 0; j < T * fs[0]; j++) { // �ش� �ð���ŭ a * sin(2*pi*f*t)�� ���ü�(fs[0]*T)��ŭ ����Ͽ� data�� �ֱ�
//                data[data_ind + j] += (short)(a * sin(2.0 * pi * f * j * dt));   // a ����, f ���ļ�, N ���ü�
//            }
//            data_ind += T * fs[0]; //�׸��� �� �����͸�ŭ array �ε����� �߰��ؼ� ���� �� ������ ���ڸ��� ������ �ϱ�
//        }
//    }
//    // ���� wave file�� ������� sample�� write�Ѵ�.
//    yy.write((char*)data, N * sizeof(short));
//    // ���� wave file �ݱ�
//    yy.close();
//
//    system("start my3.wav");
//    return 11;
//}
