#include "courier.h"
#include <string>

using namespace std;

void Courier::pause(){
    cout << "Presione [ENTER] para continuar...";
    getchar();
}

Courier::Courier(PackageList* p) : packageListRef(p){
    mainMenu();
}


void Courier::mainMenu(){
    char op;

    do{
        ///system("color f1");
        system("cls");
        cout << "          Paqueterias SP" << endl << endl;
        cout << "      Administracion de paquetes" << endl << endl;
        cout << "Introduzca que se desea hacer con los paquetes" << endl << endl;

        cout << "|-[1] Agregar paquete-----------------|" << endl
         << "|-[2] Eliminar paquete----------------|" << endl
         << "|-[3] Mostrar todos los paquetes------|" << endl
         << "|-[4] Eliminar todos los paquetes-----|" << endl
         << "|-[5] Guardar al disco (respaldar)----|" << endl
         << "|-[6] Leer del disco (recuperar)------|" << endl
         << "|-[0] Salir --------------------------|" << endl
         << "|-----Escoja una opcion (1,2,3,0)-----|";

        cin >> op;
        cin.ignore();

        switch(op){
            case '1':
                addPackage();
                break;
            case '2':
                deleteOnePackage();
                break;
            case '3':
                showAllPackages();
                break;
            case '4':
                deleteAllPackages();
                break;
            case '5':
                writeToDisk();
                break;
            case '6':
                readFromDisk();
                break;
            case '0':
                cout << "Saliendo..." <<endl << endl;
                ///pause();
                break;
            default:
                cout << "Escoja una opcion valida" << endl << endl;
                pause();
        }
    }while(op != '0');
}

void Courier::addPackage(){

    string myStr;

    PackageNode* pos;
    Package myPackage;

    system("cls");

    cout << "Agregar nuevo paquete" << endl << endl;

    cout << "ID de paquete: ";
    getline(cin, myStr);

    myPackage.setId(myStr);

    pos = packageListRef->findData(myPackage);

    if(pos != nullptr){
        cout << "ID ya registrada";

        pause();

        return;
    }

    cout << "Origen del paquete: ";
    getline(cin, myStr);

    myPackage.setOrigin(myStr);

    cout << "Destino del paquete: ";
    getline(cin, myStr);

    myPackage.setDestiny(myStr);

    cout << "Peso del paquete(kg): ";
    cin >> myStr;

    myPackage.setWeight(myStr);


    try{
        packageListRef->insertFirst(myPackage);
    }catch (ListException ex){
        cout << "Ha ocurrido un problema: ";
        cout << ex.what() <<endl;
        cout << "Si vuelve a ocurrir llame al gerente" << endl << endl;

        return;
    }

    cout << endl << "Paquete agregado de manera exitosa";
    pause();
}

void Courier::deleteOnePackage(){
    char op;
    do{
        system("cls");
        cout << "Se eliminara el PRIMER PAQUETE" << endl;
        cout << "Esta seguro de que quiere continuar? esta accion no se puede revertir (s/n)";
        cin >> op;
        cin.ignore();
        op = toupper(op);
        if (op == 'N'){
            cout << "No se eliminara el PAQUETE..." << endl << endl;
            pause();
            return;
        }
        else if(op == 'S'){
            packageListRef->deleteData();
            system("cls");
            cout << "PAQUETE eliminado satisfactoriamente" << endl << endl;
            pause();
        }
        else{
            cout << "Escoja una opcion valida..." << endl;
            pause();
        }
    }while(op != 'S');
}

void Courier::showAllPackages(){
    system("cls");
    cout << "Listado de Paquetes" << endl << endl;

    cout << packageListRef->toString();

    cout << endl << endl;
    pause();
}

void Courier::deleteAllPackages(){
    char op;
    do{
        system("cls");
        cout << "Se eliminaran TODOS los paquetes" << endl;
        cout << "Esta seguro de que quiere continuar? esta accion no se puede revertir (s/n)";
        cin >> op;
        cin.ignore();
        op = toupper(op);
        if (op == 'N'){

            cout << endl << "No se eliminara la lista..." << endl << endl;
            pause();
            return;
        }
        else if(op == 'S'){
            system("cls");
            packageListRef->deleteAll();
            cout << endl << "Paquetes eliminados satisfactoriamente" << endl << endl;
            pause();
        }
        else{
            cout << "Escoja una opcion valida...";
            pause();
        }
    }while(op != 'S');

}

void Courier::writeToDisk(){
    system("cls");

    cout << "Exportando lista..." << endl << endl;

    try{
        packageListRef->writeToDisk("packages.txt");
    }catch(ListException ex){
        cout << "Surgio un problema" << endl;
        cout << ex.what() << endl;

        pause();

    return;
    }

    cout << "Se ha exportado la lista exitosamente" << endl;
    pause();
}

void Courier::readFromDisk(){
    system("cls");

    cout << "Importando lista..." << endl << endl;

    try{
        packageListRef->readFromDisk("packages.txt");
    }catch(ListException ex){
        cout << "Surgio un problema" << endl;
        cout << ex.what() << endl;

        pause();

    return;
    }

    cout << "Se ha importado la lista exitosamente" << endl;
    pause();
}
