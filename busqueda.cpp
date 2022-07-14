#include <iostream>
#include <vector>

bool busquedaLineal(std::vector<int> &numeros, int numero)
{
    // O(N)

    // Complejidad de espacio es O(1)
    for (const auto &num : numeros)
    {
        if (numero == num)
        {
            return true;
        }
    }
    return false;
}

bool busquedaBinaria(std::vector<int> &numeros, int numero)
{
    int medio;
    int izquierda = 0;
    int derecha = numeros.size() - 1;
    size_t vueltas = 0;

    while (izquierda <= derecha)
    {
        vueltas++;
        medio = (derecha + izquierda) / 2;
        // std::cout << "medio = " << medio << std::endl;
        // std::cout << "derecha = " << derecha << std::endl;
        // std::cout << "izquierda = " << izquierda << std::endl;
        // std::cout << "numeros[medio] = " << numeros[medio] << std::endl;

        if (numero < numeros[medio])
        {
            derecha = medio - 1;
        }
        else if (numero > numeros[medio])
        {
            izquierda = medio + 1;
        }
        else
        {
            std::cout << "Se requirió " << vueltas << " vueltas para dar con la respuesta" << std::endl;
            return true;
        }
    }
    std::cout << "Se requirió " << vueltas << " cantidad de vueltas para dar con la respuesta" << std::endl;

    return false;
}

int main()
{
    std::vector<int> numeros = {1, 4, 6, 7, 9, 11, 19, 21, 49};
    int numero = 1998;
    std::cout << busquedaBinaria(numeros, numero) << std::endl;
    return 0;
}