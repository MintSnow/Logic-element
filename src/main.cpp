#include "C:/Users/sweet/Desktop/projects/Logic-element/lib/logic_element.h"

using namespace Program3;

int main() {
    int n, m;
    char st;
    Clamp cl;
    int key1 = -1;
    while (1) {
        std::cout << "__________________________________" << std::endl;
        std::cout << "Operation list:" << std::endl;
        std::cout << "0. Quit;" << std::endl;
        std::cout << "1. Initialize logic element as an invertor;" << std::endl;
        std::cout << "2. Initialize logic element with numbers of input and output clamps;" << std::endl;
        std::cout << "3. Initialize logic element with number of clamps;" << std::endl;
        std::cout << "Enter operation code: --> ";
        std::cin >> key1;
        if (key1 == 0) 
            break;
        LogElement le;
        try {
            switch (key1) {
                case 1: {
                    LogElement le;
                }
                break;
                case 2: {
                    std::cout << "Enter number of input clamps: --> ";
                    std::cin >> n;
                    std::cout << "Enter number of output clamps: --> ";
                    std::cin >> m;
                    LogElement le(n, m);
                }
                break;
                case 3: {
                    std::cout << "Enter number of clamps: --> ";
                    std::cin >> n;
                    LogElement le(n);
                }
                break;
            }
        }
        catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
            continue;
        }
        int key2 = -1;
        while (1) {
            std::cout << "Choose an operation:" << std::endl;
            std::cout << "0. Quit;" << std::endl;
            std::cout << "1. Enter statements of all clamps;" << std::endl;
            std::cout << "2. Show a logic element;" << std::endl;
            std::cout << "3. Enter statement of a clamp by its number;" << std::endl;
            std::cout << "4. Get statement of a clamp by its number;" << std::endl;
            std::cout << "5. Increase number of ports of a clamp by one;" << std::endl;
            std::cout << "6. Decrease number of ports of a clamp by one;" << std::endl;
            std::cout << "7. Add clamp to a logic element." << std::endl;
            std::cout << "Enter operation code: --> ";
            std::cin >> key2;
            if (key2 == 0)
                break;
            try {
                switch (key2) {
                    case 1: {
                        std::cout << "Enter values of signal statements: 0, 1 or X for undefined statement." << std::endl;
                        std::cin >> le;
                    }
                    break;
                    case 2: {
                        std::cout << "Your logic element is:" << std::endl;
                        std::cout << le << std::endl;
                    }
                    break;
                    case 3: {
                        std::cout << "Enter number of a clamp: --> ";
                        std::cin >> n;
                        std::cout << "Enter signal statement: 0, 1 or X --> ";
                        std::cin >> st;
                        le(n, st);
                    }
                    break;
                    case 4: {
                        std::cout << "Enter number of a clamp: --> ";
                        std::cin >> n;
                        std::cout << "Signal: " << le[n] << std::endl;
                    }
                    break;
                    case 5: {
                        std::cout << "Enter number of a clamp: --> ";
                        std::cin >> n;
                        le.connect(n);
                    }
                    break;
                    case 6: {
                        std::cout << "Enter number of a clamp: --> ";
                        std::cin >> n;
                        le.disconnect(n);
                    }
                    break;
                    case 7: {
                        std::cout << "Enter type of clamp: 0 for input, 1 for output --> ";
                        std::cin >> n;
                        if (n == 0)
                            cl.t = input;
                        else if (n == 1)
                            cl.t = output; //check!
                        std::cout << "Enter number of ports: not above 1 for input clamp and not above 3 for output clamp --> ";
                        std::cin >> cl.ports;
                        if (cl.ports != 0) {
                            std::cout << "Enter signal statement: 0, 1 or X --> ";
                            std::cin >> cl.signal;
                        }
                        else {
                            cl.signal = 'X';
                        }
                        le += cl;
                    }
                    break;
                }
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
                break;
            }
        }
    }
    return 0;
}