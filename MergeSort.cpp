#include <iostream>

using namespace std;

void Input(int *A, int N)
{
    for (int i=0; i<N; i++)
        cin >> A[i];
}
void Output(int *A, int N)
{
    for (int i=0; i<N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Mixed(int *&A, int lBegin, int rBegin, int rEnd)
{
    int tmp;
    while (A[rBegin]<A[rBegin-1])
    {
        if (A[lBegin]<=A[rBegin]) lBegin++;
        else
        {
            tmp=rBegin;
            while (A[lBegin]>A[tmp] && tmp <= rEnd) {tmp++;}
            //cout << endl << "swap " << A[lBegin] << " vs " << A[tmp-1] << endl;
            swap(A[lBegin],A[tmp-1]);
        }
    }
}

void MergeSort(int *&A, int Bg, int Ed)
{
    int i=Bg, r=0, f1, f2;
    while (i<Ed)
    {
        f1=i;
        while (A[i]<=A[i+1]) i++;
        r++;
        if (i<Ed)
        {
            f2=++i;
            cout << endl << f1 << " " << f2 << endl;
            while (A[i]<=A[i+1]) i++;
            r++;
            Mixed(A,f1,f2,i);
        }
        i++;
    }
    if (r>=2) MergeSort(A,Bg,Ed);
}

int main()
{
    int N;
    cout << "N= ";
    cin >> N;
    int *A= new int [N];
    Input(A,N);

    MergeSort(A,0,N-1);
    Output(A,N);
    return 0;
}
