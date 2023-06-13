#include <iostream>
#include <random>
#include <vector>



void imprimirPremios(const  std::vector< std::string>& premios) 
{
   std::cout << "=== Premios ===" << std::endl;
    for (const auto& premio : premios) {
        std::cout << premio << std::endl;
    }
    std::cout << "===============" << std::endl;
}

int main() 
{
    setlocale(LC_ALL, "es_MX.UTF-8");
    std::random_device rd;
    std::mt19937 gen(rd());
    bool continuar = true;

   while (continuar)
   {
    std::vector< std::string> premios = { "Sacar 10 en mate", "Una rokaleta", "Una cachetada", "Una nalgada del roris", "La maestra nos pasa a todos con 10" };
    std::vector<double> probabilidades = { 0.3, 0.2, 0.15, 0.25, 0.1 };


    double sumaProbabilidades = 0.0;
    for (const auto& probabilidad : probabilidades) 
    {
        if (probabilidad < 0.0 || probabilidad > 1.0) 
        {
        return 1;
        }
        sumaProbabilidades += probabilidad;
    }
    if (sumaProbabilidades != 1.0) 
    {
    return 1;
    }


    std::cout << "Presiona Enter para hacer girar la ruleta...";
    std::cin.get();

    
    std::discrete_distribution<> dist(probabilidades.begin(), probabilidades.end());
    int numeroSeleccionado = dist(gen);

    
    std::string premioGanado = premios[numeroSeleccionado];

    
    std::cout << "¡Has ganado el premio: " << premioGanado << "!" << std::endl;

    
    imprimirPremios(premios);
   
   }
    return 0;
}
