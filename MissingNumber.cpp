#include <iostream>

using namespace std;

// Una función para cambiar dos elementos
void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int arr[], int n, int i)
{
  int largest = i; // Inicializar el más grande como la raíz
  int l = 2 * i + 1; // izquierda= 2*i + 1
  int r = 2 * i + 2; // derecha= 2*i + 2

  // Si el hijo izquierdo es más largo que la raíz
  if (l < n && arr[l] > arr[largest])
    largest = l;

  // Si el hijo derecho es más largo que el más largo total
  if (r < n && arr[r] > arr[largest])
    largest = r;

  // Si el mayor no es la raíz
  if (largest != i) {
    swap(arr[i], arr[largest]);

  // Recursivamente crear el sub-arbol y usar la función heapify en el
  heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n)
{
  // Construir la estructura de árbol (reorganizar el arreglo)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // Extraer los elementos uno por uno de la estructura
  for (int i = n - 1; i >= 0; i--)
  {
    // Mover la raíz actual al final
    swap(arr[0], arr[i]);
    // llamar la función heapify en la estructura reducida
    heapify(arr, i, 0);
  }
}

/* Función para imprimir el arreglo */
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << endl;
}

int main(){
  int t,n,p;
  string line;

  cin >> t;

  int answers[t];

  for(int k=0; k < t; k++)
  {
    cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    heapSort(a, n-1);

    if(a[n-1]%2 == 0)
    {
      answers[k] = a[n-1] + 2;
    }
    else
    {
      answers[k] = a[n-1] + 1;
    }
  }

  printArray(answers, t);

}
