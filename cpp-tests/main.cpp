// #include <cctype>
// // #include <ctime>
// // #include <fstream>
// // #include <iomanip>
// // #include <ios>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <set>
// // #include <locale>
// // #include <map>
// #include <ostream>
// // #include <string>
// #include <vector>

// void log_message(const std::string& message) {
//     auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//     std::clog << "[" << std::ctime(&now) << "] " << message << std::endl;
// }

int main()
{
	{
		// std::ofstream	log("LogFile.txt");
		// std::clog.rdbuf(log.rdbuf());
		// std::cout.fill('.');
		// std::cout << "With default setting : [" << std::setw(10) << 40 << "]\n";
		// std::cerr << "Bad string format!";
		// std::clog << std::setw(10) << "Ligne:29 buff!" << time(0) << std::endl;
		// std::cout.write("lol", 3) << std::endl;
		// std::cout << "hello guys" << std::endl;
		// std::cout << std::cout.tellp();
		// log_message("Démarrage de l'application");
		// log_message("Un événement s'est produit");
		// log_message("Fin de l'application");
	}
	{
		//	Tres utile !
		//	pointer on function from, to, write in, function.
		// transform(str.begin(),str.end(),str.begin(),::tolower);
		// std::set<char> set(begin(str), end(str));
		// std::cout << set.size() << std::endl;
	}
	{	//		iterator
		// std::string	str("bonjour a toRus");
		// bool *lol;
		//
		// std::string::iterator it;
		// it = str.begin();
		// str.clear();
		// std::cout << str << std::endl;
		// std::cout << it[0] << std::endl;
	}
	// std::cout << (tmp += " le monde") << std::endl;
	// const char *str = tmp.data();
	// const char *str = tmp.c_str();
	// const char *str = tmp.copy;
	// std::vector<std::string> lol;
	// std::vector<std::string>::iterator it;
	{
		// std::map<int, std::string>	map;
		// std::map<int, std::string>::iterator it;
		// map[0] = "lol";
		// map[10] = "Berlin";
		// for (it = map.begin(); it != map.end(); it++){
		// 	std::cout << it->second << std::endl;
		// }
	}
	{
		// std::allocator<int> alloc;
		//
		// // Allouer de la mémoire brute pour 5 entiers
		// int* ptr = alloc.allocate(5);
		//
		// // Construire les objets dans la mémoire allouée
		// for (int i = 0; i < 5; ++i) {
		// 	alloc.construct(ptr + i, i * 10); // Initialise avec les valeurs 0, 10, 20, 30, 40
		// }
		//
		// // Afficher les valeurs
		// for (int i = 0; i < 5; ++i) {
		// 	std::cout << ptr[i] << " ";
		// }
		// std::cout << std::endl;
		//
		// // Détruire les objets
		// for (int i = 0; i < 5; ++i) {
		// 	alloc.destroy(ptr + i);
		// }
		//
		// // Libérer la mémoire brute
		// alloc.deallocate(ptr, 5);
	}
	{
		std::string lol("           w         ");
		std::string tmp = lol.substr();
		std::cout << tmp << std::endl;
	}
}
