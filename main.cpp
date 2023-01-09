#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int tam = 100;

struct Canciones
{
    string id;
    string nombre;
    string artista;
    string duracion;
    string meGusta;
};

struct ListaReproduccion
{
    string id;
    string nombre;
    int cantCanciones;
    string listaCanciones [tam];
};

struct Albumes
{
    string id;
    string nombre;
    int cantCanciones;
    string listaCanciones [tam];
    int anoLanzamiento;
    string artista;
};

struct Artistas
{
    string id;
    string nombre;
    int cantAlbum;
    string listaAlbumes [tam];
    int cantOyentes;
};

Artistas artistas [tam];
Albumes albumes [tam];
Canciones canciones [tam];
ListaReproduccion listas [tam];
string archivoAlbum = "Album.txt";
string archivoArtista = "Artista.txt";
string archivoCancion = "Cancion.txt";
string archivoPlayList = "PlayList.txt";

int contArtistas = 0, cantAlb = 0, contAlbumes = 0, cantCanciones = 0, cantCanciones2 = 0, contCanciones = 0, contListas = 0;

Artistas  llenarArtista (int& cantAlb);
void llenarArtistas (Artistas artistas [], int tam, int& contArtistas, int& cantAlb);
Albumes llenarAlbum(int& cantCanciones);
void llenarAlbumes (Albumes albumes [], int tam, int& contAlbumes, int& cantCanciones);
Canciones llenarCancion ();
void llenarCanciones (Canciones canciones [], int tam, int& contCanciones);
ListaReproduccion llenarPlayList(int& cantCanciones2);
void llenarPlayLists (ListaReproduccion listas [], int tam, int& cantCanciones2, int& contListas);
void menuIngresarInformacion ();

void cargarAlbum(Albumes albumes[], int tam, int& contAlbumes, int& cantCanciones);
void cargarArtista(Artistas artistas [], int tam, int& contArtistas, int& cantAlb);
void cargarPlayList(ListaReproduccion listas [], int tam, int& cantCanciones2, int& contListas);
void cargarCanciones (Canciones canciones [], int tam, int& contCanciones);
void menuIngresarInformacionArchivo();
void menuTipoCarga ();

void modificarArtista (Artistas artistas[], int& contArtistas, int& cantAlb, int tam);
void modificarAlbum (Albumes albumes[], int& contAlbumes, int& cantCanciones, int tam);
void modificarCancion (Canciones canciones [], int& contCanciones);
void modificarPlaylist (ListaReproduccion listas [],int tam,int& contListas,int& cantCanciones2);
void menuModificarInformacion ();


void buscarArtista (Artistas artistas[], int& contArtistas);
void buscarAlbum (Albumes albumes[], int& contAlbumes);
void buscarCancion (Canciones canciones [], int& contCanciones);
void buscarPlayList (ListaReproduccion listas [], int& contListas);
void menuBusquedaInformacion();


void impresionArtistas (Artistas artistas [], int& contArtistas);
void impresionAlbumes (Albumes albumes [], int& contAlbumes);
void impresionCanciones (Canciones canciones [], int& contCanciones);
void impresionPlayList (ListaReproduccion listas [], int& contListas);
void menuImprimir ();


void menuPrincipal ();


int main()
{
    menuPrincipal();
    return 0;
}

Artistas  llenarArtista (int& cantAlb)
{
    Artistas art;

    cin.ignore(1);
    cout << "Por favor digite el id del artista: ";
    getline (cin,art.id);
    cout << "Por favor digite el nombre del artista: ";
    getline (cin,art.nombre);
    cout << "Por favor digite la cantidad de albumes que tiene el artista: ";
    cin >> art.cantAlbum;
    cin.ignore(1);

    while (cantAlb < art.cantAlbum)
    {
        cout << "Por favor digite el nombre del album numero " << cantAlb+1 << " : ";
        getline (cin,art.listaAlbumes[cantAlb]);
        cantAlb++;
    }

    cout << "Por favor digite la cantidad de oyentes que tiene el artista: ";
    cin >> art.cantOyentes;
    cout << endl;

    return art;
}
void llenarArtistas (Artistas artistas [], int tam, int& contArtistas, int& cantAlb)
{
    cantAlb = 0;

    if (contArtistas < tam)
    {
        artistas[contArtistas] = llenarArtista(cantAlb);
        contArtistas++;
    }
    else
    {
        cout << "La lista de artistas esta llena" << endl;
    }
    cout << endl;
    impresionArtistas (artistas,contArtistas);
}
Albumes llenarAlbum(int& cantCanciones)
{
    Albumes alb;

    cin.ignore(1);
    cout << "Por favor digite el id del album: ";
    getline(cin,alb.id);
    cout << "Por favor digite el nombre del album: ";
    getline(cin,alb.nombre);
    cout << "Por favor digite la cantidad de canciones que tiene el album: ";
    cin >> alb.cantCanciones;
    cin.ignore(1);

    while (cantCanciones < alb.cantCanciones)
    {
        cout << "Por favor digite el nombre de la cancion numero " << cantCanciones+1 << " : ";
        getline(cin,alb.listaCanciones[cantCanciones]);
        cantCanciones++;
    }

    cout << "Por favor digite el anho de lanzamiento: ";
    cin >> alb.anoLanzamiento;
    cin.ignore(1);
    cout << "Por favor digite el nombre del artista del album: ";
    getline(cin,alb.artista);
    cout << endl;

    return alb;
}
void llenarAlbumes (Albumes albumes [], int tam, int& contAlbumes, int& cantCanciones)
{
    cantCanciones = 0;

    if (contAlbumes <= tam)
    {
        albumes[contAlbumes] = llenarAlbum (cantCanciones);
        contAlbumes++;
    }
    else
    {
        cout << "La lista de albumes esta llena" << endl;
    }
    cout << endl;
    impresionAlbumes (albumes,contAlbumes);
}
Canciones llenarCancion ( )
{
    Canciones can;

    cin.ignore(1);
    cout << "Por favor digite el id de la cancion ";
    getline(cin,can.id);
    cout << "Por favor digite el nombre de la cancion: ";
    getline(cin,can.nombre);
    cout << "Por favor digite el artista de la cancion: ";
    getline(cin,can.artista);
    cout << "Por favor digite la duracion de la cancion: ";
    getline(cin,can.duracion);
    cout << "Por favor digite si le gusta o no la cancion (true/false): ";
    getline(cin,can.meGusta);

    return can;
}
void llenarCanciones (Canciones canciones [], int tam, int& contCanciones)
{
    if (contCanciones <= tam)
    {
        canciones[contCanciones] = llenarCancion();
        contCanciones++;
    }
    else
    {
        cout << "la lista de canciones esta llena" << endl;
    }
    cout << endl;
    impresionCanciones (canciones,contCanciones);
}
ListaReproduccion llenarPlayList(int& cantCanciones2)
{
    ListaReproduccion list;

    cin.ignore(1);
    cout << "Por favor digite el id de la playList ";
    getline(cin,list.id);
    cout << "Por favor digite el nombre de la playList: ";
    getline(cin,list.nombre);
    cout << "Por favor digite la cantidad de canciones de la playList: ";
    cin >> list.cantCanciones;
    cin.ignore(1);

    while (cantCanciones2 < list.cantCanciones)
    {
        cout << "Por favor digite el nombre de la cancion numero " << cantCanciones2 + 1 << " : ";
        getline(cin,list.listaCanciones[cantCanciones2]);
        cantCanciones2++;
    }

    return list;
}
void llenarPlayLists (ListaReproduccion listas [], int tam, int& cantCanciones2, int& contListas)
{
    cantCanciones2 = 0;

    if (contListas <= tam)
    {
        listas[contListas] = llenarPlayList(cantCanciones2);
        contListas++;
    }
    else
    {
        cout << "La lista de Playlist esta llena" << endl;
    }
    cout << endl;
    impresionPlayList (listas,contListas);
}
void menuIngresarInformacion () {

    int opcion = 0, opcion2 = 0;

    do {
        system("cls");
        cout << " --------------------------------- MENU INGRESAR INFORMACION --------------------------------- " << endl;
        cout << "1. Agregar nuevo artista" << endl;
        cout << "2. Agregar nueva cancion" << endl;
        cout << "3. Agregar nuevo album" << endl;
        cout << "4. Crear una nueva PlayList" << endl;
        cout << "5. Volver al menu princial" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system ("CLS");
                llenarArtistas(artistas, tam, contArtistas, cantAlb);
                system("Pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                llenarCanciones(canciones, tam, contCanciones);
                system("Pause");
                break;
            }
            case 3:
            {
                system ("CLS");
                llenarAlbumes(albumes, tam, contAlbumes, cantCanciones);
                system("Pause");
                break;
            }
            case 4:
            {
                system ("CLS");
                llenarPlayLists(listas, tam, cantCanciones2, contListas);
                system("Pause");
                break;
            }
            case 5:
            {
                break;
            }

            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    } while (opcion != 5);
}

void cargarAlbum(Albumes albumes[], int tam, int& contAlbumes, int& cantCanciones)
{
    string linea;
    ifstream archivo;
    archivo.open (archivoAlbum);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }

    while (!archivo.eof())
    {
        cantCanciones = 0;

        if (contAlbumes <= tam)
        {
            getline(archivo, linea);
            albumes[contAlbumes].id = linea;
            getline(archivo, linea);
            albumes[contAlbumes].nombre = linea;
            getline(archivo, linea);
            albumes[contAlbumes].cantCanciones = stoi(linea);

            for (int i = 0; i < albumes[contAlbumes].cantCanciones; i++)
            {
                getline(archivo, linea);
                albumes[contAlbumes].listaCanciones[cantCanciones] = linea;
                cantCanciones++;
            }

            getline(archivo, linea);
            albumes[contAlbumes].anoLanzamiento = stoi(linea);
            getline(archivo, linea);
            albumes[contAlbumes].artista = linea;
            contAlbumes++;
        }
        else
        {
            cout << "La lista de albumes esta llena" << endl;
        }
    }
    cout << "El archivo 'Album.txt' se cargo correctamente" << endl;
    archivo.close();
    cout << endl;
    impresionAlbumes (albumes,contAlbumes);
}
void cargarArtista(Artistas artistas [], int tam, int& contArtistas, int& cantAlb)
{
    string linea;
    ifstream archivo;
    archivo.open (archivoArtista);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }

    while (!archivo.eof())
    {
        cantAlb = 0;

        if (contArtistas <= tam)
        {
            getline(archivo, linea);
            artistas[contArtistas].id = linea;
            getline (archivo,linea);
            artistas[contArtistas].nombre = linea;
            getline (archivo,linea);
            artistas[contArtistas].cantAlbum = stoi(linea);

            for (int i = 0; i < artistas[contArtistas].cantAlbum ; i++)
            {
                getline (archivo,linea);
                artistas[contArtistas].listaAlbumes[cantAlb] = linea;
                cantAlb++;
            }

            getline (archivo,linea);
            artistas[contArtistas].cantOyentes = stoi(linea);
            contArtistas++;
        }
        else
        {
            cout << "La lista de artistas esta llena" << endl;
        }
    }
    cout << "El archivo 'Artistas.txt' se cargo correctamente" << endl;
    archivo.close();
    cout << endl;
    impresionArtistas (artistas,contArtistas);
}
void cargarCanciones (Canciones canciones [], int tam, int& contCanciones)
{
    string linea;
    ifstream archivo;
    archivo.open (archivoCancion);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }

    while (!archivo.eof())
    {
        if (contCanciones <= tam)
        {
            getline(archivo, linea);
            canciones[contCanciones].id = linea;
            getline(archivo, linea);
            canciones[contCanciones].nombre = linea;
            getline(archivo, linea);
            canciones[contCanciones].artista = linea;
            getline(archivo, linea);
            canciones[contCanciones].duracion = linea;
            getline(archivo, linea);
            canciones[contCanciones].meGusta = linea;
            contCanciones++;
        }
        else
        {
            cout << "La lista de canciones esta llena" << endl;
        }
    }
    cout << "El archivo 'Canciones.txt' se cargo correctamente" << endl;
    archivo.close();
    cout << endl;
    impresionCanciones (canciones,contCanciones);
}
void cargarPlayList(ListaReproduccion listas [], int tam, int& cantCanciones2, int& contListas)
{
    string linea;
    ifstream archivo;
    archivo.open (archivoPlayList, ios::in);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }

    while (!archivo.eof())
    {
        cantCanciones2 = 0;

        if (contArtistas <= tam)
        {
            getline(archivo, linea);
            listas[contListas].id = linea;
            getline (archivo,linea);
            listas[contListas].nombre = linea;
            getline (archivo,linea);
            listas[contListas].cantCanciones = stoi(linea);

            for (int i = 0; i < listas[contListas].cantCanciones; i++)
            {
                getline (archivo,linea);
                listas[contListas].listaCanciones[cantCanciones2] = linea;
                cantCanciones2++;
            }
            contListas++;
        }
        else
        {
            cout << "La lista de playList esta llena" << endl;
        }
    }
    cout << "El archivo 'PlayList.txt' se cargo correctamente" << endl;
    archivo.close();
    cout << endl;
    impresionPlayList (listas,contListas);
}
void menuIngresarInformacionArchivo()
{
    int opcion = 0;

    do {
        system("cls");
        cout << " --------------------------------- MENU INGRESAR INFORMACION DESDE ARCHIVO --------------------------------- " << endl;
        cout << "1. Agregar artistas" << endl;
        cout << "2. Agregar canciones" << endl;
        cout << "3. Agregar albumes" << endl;
        cout << "4. Crear PlayLists" << endl;
        cout << "5. Volver al menu princial" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system ("CLS");
                cargarArtista(artistas,tam,contArtistas,cantAlb);
                system("Pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                cargarCanciones (canciones,tam,contCanciones);
                system("Pause");
                break;
            }
            case 3:
            {
                system ("CLS");
                cargarAlbum(albumes,tam,contAlbumes,cantCanciones);
                system("Pause");
                break;
            }
            case 4:
            {
                system ("CLS");
                cargarPlayList(listas,tam,cantCanciones2,contListas);
                system("Pause");
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    } while (opcion != 5);
}
void menuTipoCarga () {

    int opcion = 0;

    do {
        system ("CLS");
        cout << " --------------------------------- MENU TIPO DE CARGA --------------------------------- " << endl;
        cout << "1. Cargar la informacion por consola" << endl;
        cout << "2. Cargar la informacion por archivo" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor digite su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system("CLS");
                menuIngresarInformacion();
                system("Pause");
                break;
            }
            case 2:
            {
                system("CLS");
                menuIngresarInformacionArchivo();
                system("Pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    }while (opcion != 3);
}


void impresionArtistas (Artistas artistas [], int& contArtistas)
{
    for (int i = 0; i < contArtistas; i++)
    {
        cout << "---------------------------- ARTISTA " << i+1 << " ----------------------------" << endl << endl;
        cout << "Id: " << artistas[i].id << endl;
        cout << "Nombre: " << artistas[i].nombre << endl;
        cout << "Cantidad de albumes publicados: " << artistas[i].cantAlbum << endl;
        cout << "Lista de albumes: " << endl;

        for (int j = 0; j < artistas[i].cantAlbum; j++)
        {
            cout << "Album " << j+1 << " : " << artistas[i].listaAlbumes[j] << endl;
        }

        cout << "Cantidad de oyentes: " << artistas[i].cantOyentes << endl;
        cout << endl;
    }
}
void impresionAlbumes (Albumes albumes [], int& contAlbumes)
{
    for (int i = 0; i < contAlbumes; i++)
    {
        cout << "---------------------------- ALBUM " << i+1 << " ----------------------------" << endl << endl;
        cout << "Id: " << albumes[i].id << endl;
        cout << "Nombre: " << albumes[i].nombre << endl;
        cout << "Cantidad de canciones del album: " << albumes[i].cantCanciones << endl;
        cout << "Lista de canciones del album: " << endl;

        for (int j = 0; j < albumes[i].cantCanciones; j++)
        {
            cout << "Cancion " << j+1 << " : " << albumes[i].listaCanciones[j] << endl;
        }

        cout << "Ano de lanzamiento del album: " << albumes[i].anoLanzamiento << endl;
        cout << "Nombre del artista del album: " << albumes[i].artista << endl;
        cout << endl;
    }
}
void impresionCanciones (Canciones canciones [], int& contCanciones)
{
    for (int i = 0; i < contCanciones; i++)
    {
        cout << "---------------------------- CANCION " << i+1 << " ----------------------------" << endl << endl;
        cout << "Id: " << canciones[i].id << endl;
        cout << "Nombre: " << canciones[i].nombre << endl;
        cout << "Nombre del artista: " << canciones[i].artista << endl;
        cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
        cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
        cout << endl;
    }
}
void impresionPlayList (ListaReproduccion listas [], int& contListas)
{
    for (int i = 0; i < contListas; i++)
    {
        cout << "---------------------------- PLAYLIST " << i+1 << " ----------------------------" << endl << endl;
        cout << "Id: " << listas[i].id << endl;
        cout << "Nombre: " << listas[i].nombre << endl;
        cout << "Cantidad de canciones del album: " <<listas[i].cantCanciones << endl;
        cout << "Canciones de la Playlist: " << endl;

        for (int j = 0; j < listas[i].cantCanciones; j++)
        {
            cout << "Cancion " << j+1 << " : " << listas[i].listaCanciones[j] << endl;
        }

        cout << endl;
    }
}
void menuImprimir ()
{
    int opcion = 0;
    do{
        system("cls");
        cout << " --------------------------------- MENU IMPRIMIR --------------------------------- " << endl;
        cout << "1. Imprimir Artistas" << endl;
        cout << "2. Imprimir Albumes" << endl;
        cout << "3. Imprimir Canciones" << endl;
        cout << "4. Imprimir Playlists" << endl;
        cout << "5. Volver al Menu Principal" << endl;
        cout << "Por favor seleccione su opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
            {
                system ("CLS");
                impresionArtistas(artistas,contArtistas);
                system ("Pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                impresionAlbumes(albumes,contAlbumes);
                system ("Pause");
                break;
            }
            case 3:
            {
                system ("CLS");
                impresionCanciones(canciones,contCanciones);
                system ("Pause");
                break;
            }
            case 4:
            {
                system ("CLS");
                impresionPlayList(listas,contListas);
                system ("Pause");
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }

    }while (opcion != 5);
}


void buscarArtista (Artistas artistas[], int& contArtistas)
{
    int idArtista;
    string aux;
    bool bandera = false;

    do
    {
        bandera = false;
        system ("CLS");
        cout << "Por favor digite el id del artista que quiere buscar: ";
        cin >> idArtista;
        cout << endl;

        for (int i = 0; i < contArtistas; i++)
        {
            if (idArtista == stoi (artistas[i].id))
            {
                bandera = true;
                cout << "---------------------------- ARTISTA " << i+1 << " ----------------------------" << endl << endl;
                cout << "Id: " << artistas[i].id << endl;
                cout << "Nombre: " << artistas[i].nombre << endl;
                cout << "Cantidad de albumes publicados: " << artistas[i].cantAlbum << endl;
                cout << "Lista de albumes: " << endl;

                for (int j = 0; j < artistas[i].cantAlbum; j++)
                {
                    cout << "Album " << j+1 << " : " << artistas[i].listaAlbumes[j] << endl;
                }

                cout << "Cantidad de oyentes: " << artistas[i].cantOyentes << endl;
                break;
            }
        }

        if (!bandera)
        {
            cout << "No se encontro ningun artista con el id " << idArtista <<" en la base de datos" << endl;
        }

        cout << "Desea seguir buscando artistas (S / N): ";
        cin >> aux;
        cout << endl;

    }while (aux == "S" || aux == "s");
}
void buscarAlbum (Albumes albumes[], int& contAlbumes)
{
    int idAlbum, opcion;
    string auxNombre;
    bool bandera = false;

    do
    {
        bandera = false;
        system ("CLS");
        cout << "1. Buscar el album por nombre" << endl;
        cout << "2. Buscar el album por id" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system("cls");
                cin.ignore(1);
                cout << "Por favor digite el nombre del album que desea buscar: ";
                getline(cin, auxNombre);
                cout << endl;

                for (int i = 0; i < contAlbumes; i++)
                {
                    if (auxNombre == albumes[i].nombre)
                    {
                        bandera = true;
                        cout << "---------------------------- ALBUM " << i+1 << " ----------------------------" << endl << endl;
                        cout << "Id: " << albumes[i].id << endl;
                        cout << "Nombre: " << albumes[i].nombre << endl;
                        cout << "Cantidad de canciones del album: " << albumes[i].cantCanciones << endl;
                        cout << "Lista de canciones del album: " << endl;

                        for (int j = 0; j < albumes[i].cantCanciones; j++)
                        {
                            cout << "Cancion " << j+1 << " : " << albumes[i].listaCanciones[j] << endl;
                        }

                        cout << "Ano de lanzamiento del album: " << albumes[i].anoLanzamiento << endl;
                        cout << "Nombre del artista del album: " << albumes[i].artista << endl;
                        break;
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro ningun album con el nombre de " << auxNombre << " en la base de datos" << endl;
                }
                system ("pause");
                break;
            }
            case 2:
            {
                system("cls");
                cout << "Por favor digite el id del album que desea buscar: ";
                cin >> idAlbum;
                cout << endl;
                for (int i = 0; i < contAlbumes; i++)
                {
                    if (idAlbum == stoi(artistas[i].id))
                    {
                        bandera = true;
                        cout << "---------------------------- ALBUM " << i+1 << " ----------------------------" << endl << endl;
                        cout << "Id: " << albumes[i].id << endl;
                        cout << "Nombre: " << albumes[i].nombre << endl;
                        cout << "Cantidad de canciones del album: " << albumes[i].cantCanciones << endl;
                        cout << "Lista de canciones del album: " << endl;

                        for (int j = 0; j < albumes[i].cantCanciones; j++)
                        {
                            cout << "Cancion " << j+1 << " : " << albumes[i].listaCanciones[j] << endl;
                        }

                        cout << "Ano de lanzamiento del album: " << albumes[i].anoLanzamiento << endl;
                        cout << "Nombre del artista del album: " << albumes[i].artista << endl;
                        break;
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro ningun album con el id " << idAlbum << " en la base de datos" << endl;
                }
                system ("pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                system("cls");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
                system ("pause");
            }
        }
    }while (opcion != 3);
}
void buscarCancion (Canciones canciones [], int& contCanciones)
{
    int idCancion, opcion;
    string duracion;
    bool bandera = false;

    do
    {
        bandera = false;
        system ("CLS");
        cout << "1. Buscar cancion por id"<< endl;
        cout << "2. Buscar canciones por duracion" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                system ("CLS");
                cout << "Por favor digite el id de la cancion que desea buscar: ";
                cin >> idCancion;
                cout << endl;
                for (int i = 0; i < contCanciones; i++)
                {
                    if (idCancion == stoi (canciones[i].id))
                    {
                        bandera = true;
                        cout << "---------------------------- CANCION " << i+1 << " ----------------------------" << endl << endl;
                        cout << "Id: " << canciones[i].id << endl;
                        cout << "Nombre: " << canciones[i].nombre << endl;
                        cout << "Nombre del artista: " << canciones[i].artista << endl;
                        cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
                        cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
                        cout << endl;
                        break;
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro ninguna cancion con el id " << idCancion << " en la base de datos" << endl;
                }
                system ("pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                cin.ignore(1);
                cout << "Por favor digite la duracion de las canciones que desea buscar (Ej = 3:24): ";
                getline(cin,duracion);
                cout << endl;

                for (int i = 0; i < contCanciones; i++)
                {
                    if (duracion == canciones[i].duracion)
                    {
                        bandera = true;
                        cout << "---------------------------- CANCION " << i + 1 << " ----------------------------"
                             << endl << endl;
                        cout << "Id: " << canciones[i].id << endl;
                        cout << "Nombre: " << canciones[i].nombre << endl;
                        cout << "Nombre del artista: " << canciones[i].artista << endl;
                        cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
                        cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
                        cout << endl;
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro ninguna cancion con duracion de " << duracion << " en la base de datos" << endl;
                }
                system ("pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                system ("CLS");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
                system ("pause");
            }
        }
    }while (opcion != 3);
}
void buscarPlayList (ListaReproduccion listas [], int& contListas)
{
    int idPlayList;
    string aux;
    bool bandera = false;

    do
    {
        bandera = false;
        system ("CLS");
        cout << "Por favor digite el id de la PlayList que quiere buscar: ";
        cin >> idPlayList;
        cout << endl;

        for (int i = 0; i < contListas; i++)
        {
            if (idPlayList == stoi (listas[i].id))
            {
                bandera = true;
                cout << "---------------------------- PLAYLIST " << i+1 << " ----------------------------" << endl << endl;
                cout << "Id: " << listas[i].id << endl;
                cout << "Nombre: " << listas[i].nombre << endl;
                cout << "Cantidad de canciones del album: " <<listas[i].cantCanciones << endl;
                cout << "Canciones de la Playlist: " << endl;

                for (int j = 0; j < listas[i].cantCanciones; j++)
                {
                    cout << "Cancion " << j+1 << " : " << listas[i].listaCanciones[j] << endl;
                }
                break;
            }
        }
        if (!bandera)
        {
            cout << "No se encontro ninguna playList con el id " << idPlayList << " en la base de datos" << endl;
        }
        cout << endl;
        cout << "Desea seguir buscando artistas (S / N): ";
        cin >> aux;
    }while (aux == "S" || aux == "s");
}
void mostrarMegusta (Canciones canciones [],int& contCanciones)
{
    bool bandera = false;
    system ("CLS");

    for (int i = 0; i < contCanciones; i++)
    {
        if (canciones[i].meGusta == "true")
        {
            bandera = true;
            cout << "---------------------------- CANCION " << i + 1 << " ----------------------------" << endl << endl;
            cout << "Id: " << canciones[i].id << endl;
            cout << "Nombre: " << canciones[i].nombre << endl;
            cout << "Nombre del artista: " << canciones[i].artista << endl;
            cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
            cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
            cout << endl;
        }
    }
    if (bandera == false)
    {
        cout << "No se encontro ninguna cancion con algun me gusta" << endl;
    }
}
void exportarPlayList (ListaReproduccion listas [], int& contListas)
{
    string linea;
    bool bandera = false;
    int idPlayList;
    ofstream archivo ("PlayListExportada.txt");

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo correctamente" << endl;
    }
    else
    {
        system ("CLS");
        cout << "Por favor digite el id de la PlayList que quiere exportar: ";
        cin >> idPlayList;

        for (int i = 0; i < contListas; i++)
        {
            if (idPlayList == stoi (listas[i].id))
            {
                bandera = true;
                archivo << "---------------------------- PLAYLIST " << i+1 << " ----------------------------" << endl << endl;
                archivo << "Id: " << listas[i].id << endl;
                archivo << "Nombre: " << listas[i].nombre << endl;
                archivo << "Cantidad de canciones del album: " <<listas[i].cantCanciones << endl;
                archivo << "Canciones de la Playlist: " << endl;

                for (int j = 0; j < listas[i].cantCanciones; j++)
                {
                    archivo << "Cancion " << j+1 << " : " << listas[i].listaCanciones[j] << endl;
                }
                break;
            }
        }
        if (!bandera)
        {
            cout << "No se encontro una PlayList con el id " << idPlayList << " en la base de datos" << endl;
        }
    }
}
void menuBusquedaInformacion() {

    int opcion = 0;

    do {
        system("cls");
        cout << " --------------------------------- MENU BUSQUEDA DE INFORMACION --------------------------------- " << endl;
        cout << "1. Buscar un artista" << endl;
        cout << "2. Buscar un album" << endl;
        cout << "3. Buscar una cancion" << endl;
        cout << "4. Buscar una PlayList" << endl;
        cout << "5. Mostrar cantidad de Me Gusta's" << endl;
        cout << "6. Exportar PlayList" << endl;
        cout << "7. Volver al menu princial" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system("CLS");
                buscarArtista(artistas,contArtistas);
                system("Pause");
                break;
            }
            case 2:
            {
                system("CLS");
                buscarAlbum (albumes,contAlbumes);
                system("Pause");
                break;
            }
            case 3:
            {
                system("CLS");
                buscarCancion (canciones,contCanciones);
                system("Pause");
                break;
            }
            case 4:
            {
                system("CLS");
                buscarPlayList (listas,contListas);
                system("Pause");
                break;
            }
            case 5:
            {
                system("CLS");
                mostrarMegusta (canciones,contCanciones);
                system("Pause");
                break;
            }
            case 6:
            {
                system("CLS");
                exportarPlayList (listas,contListas);
                system("Pause");
                break;
            }
            case 7:
            {
                break;
            }
            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    } while (opcion != 7);
}


void modificarArtista (Artistas artistas[], int& contArtistas, int& cantAlb, int tam)
{
    int opcion;
    bool bandera = false;
    bool bandera2 = false;

    string nombreAlbum, nombreAlbumAux;

    do
    {
        system ("CLS");
        cout << "1. Agregar un nuevo album" << endl;
        cout << "2. Modificar un album" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                system("CLS");
                int idArtista;

                cout << "Por favor digite el id del artista al cual le quiere agregar un nuevo album: ";
                cin >> idArtista;
                cout << endl;
                for (int i = 0; i < contArtistas; i++)
                {
                    if (idArtista == stoi(artistas[i].id))
                    {
                        bandera = true;
                        cin.ignore(1);
                        cout << "Por favor digite el nombre del album quiere agregar: ";
                        getline(cin, nombreAlbum);
                        artistas[i].cantAlbum ++;
                        if(artistas[i].cantAlbum < tam)
                        {
                            artistas[i].listaAlbumes[artistas[i].cantAlbum-1] = nombreAlbum;
                            cout << "Modificacion realizada exitosamente" << endl << endl;
                            impresionArtistas(artistas,contArtistas);
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro una artista con el id " << idArtista << " dentro de la base de datos" << endl;
                    cout << endl;
                }
                system("pause");
                break;
            }
            case 2:
            {
                system("CLS");
                int idArtista;

                cout << "Por favor digite el id del artista al cual le quiere modificar un album: ";
                cin >> idArtista;
                cout << endl;

                for (int i = 0; i < contArtistas; i++)
                {
                    if (idArtista == stoi(artistas[i].id))
                    {
                        bandera = true;
                        cout << "Por favor digite el nombre del album que quiere modificar: ";
                        cin.ignore(1);
                        getline(cin, nombreAlbum);

                        for (int j = 0; j < artistas[i].cantAlbum; j++)
                        {
                            if (nombreAlbum == artistas[i].listaAlbumes[j])
                            {
                                bandera2 = true;
                                cout << "Digite el nuevo nombre que le quiere asignar al album: ";
                                getline(cin, nombreAlbumAux);
                                artistas[i].listaAlbumes[j] = nombreAlbumAux;
                                cout << "Modificacion realizada exitosamente" << endl << endl;
                                impresionArtistas(artistas,contArtistas);
                            }
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro un artista con el id " << idArtista << " en la base de datos" << endl;
                }
                if (!bandera2)
                {
                    cout << "No se encontro el nombre " << nombreAlbum << " dentro del artista con id " << idArtista << endl;
                }
                system("pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                system("CLS");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
                system("pause");
            }
        }
    }while (opcion != 3);
}
void modificarAlbum (Albumes albumes[], int& contAlbumes, int& cantCanciones, int tam)
{
    system("CLS");
    bool bandera = false;
    int idAlbum;
    string nombreCancion;

    cout << "Por favor digite el id del album al cual le quiere agregar una cancion: ";
    cin >> idAlbum;

    for (int i = 0; i < contAlbumes; i++)
    {
        if (idAlbum == stoi(albumes[i].id))
        {
            bandera = true;
            cin.ignore(1);
            cout << "Por favor digite el nombre de la cancion que quiere agregar: ";
            getline(cin, nombreCancion);
            albumes[i].cantCanciones ++;

            if(albumes[i].cantCanciones < tam)
            {
                albumes[i].listaCanciones[albumes[i].cantCanciones-1] = nombreCancion;
                cout << "Modificacion realizada exitosamente" << endl << endl;
                impresionAlbumes(albumes,contAlbumes);
            }
        }
    }
    if (!bandera)
    {
        cout << "No se encontro un album con el id " << idAlbum << " dentro de la base de datos" << endl;
    }
}
void modificarCancion (Canciones canciones [], int& contCanciones)
{
    int opcion, idCancion;
    bool bandera = false;
    bool bandera2 = false;

    do
    {
        system ("CLS");
        cout << "1. Dar me gusta a una cancion" << endl;
        cout << "2. Eliminar me gusta de una cancion" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                system ("CLS");
                cout << "Por favor digite el id de la cancion que desea darle me gusta: ";
                cin >> idCancion;

                for (int i = 0; i < contCanciones; i++)
                {
                    if (idCancion == stoi (canciones[i].id))
                    {
                        bandera = true;

                        if (canciones[i].meGusta == "false")
                        {
                            bandera2 = true;
                            canciones[i].meGusta = "true";
                            cout << "Se ha realizado el cambio satisfactoriamente" << endl << endl;

                            cout << "---------------------------- CANCION " << i+1 << " ----------------------------" << endl << endl;
                            cout << "Id: " << canciones[i].id << endl;
                            cout << "Nombre: " << canciones[i].nombre << endl;
                            cout << "Nombre del artista: " << canciones[i].artista << endl;
                            cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
                            cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro una cancion con el id " << idCancion << " dentro la base de datos" << endl;
                }
                if (!bandera2)
                {
                    cout << "Esta cancion ya tiene me gusta" << endl;
                }
                system("pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                cout << "Por favor digite el id de la cancion que desea quitarle el me gusta: ";
                cin >> idCancion;

                for (int i = 0; i < contCanciones; i++)
                {
                    if (idCancion == stoi (canciones[i].id))
                    {
                        bandera = true;
                        if (canciones[i].meGusta == "true")
                        {
                            bandera2 = true;
                            canciones[i].meGusta = "false";
                            cout << "Se ha realizado el cambio satisfactoriamente" << endl;

                            cout << "---------------------------- CANCION " << i+1 << " ----------------------------" << endl << endl;
                            cout << "Id: " << canciones[i].id << endl;
                            cout << "Nombre: " << canciones[i].nombre << endl;
                            cout << "Nombre del artista: " << canciones[i].artista << endl;
                            cout << "Duracion de la cancion: " << canciones[i].duracion << endl;
                            cout << "Me gusta esta cancion: " << canciones[i].meGusta << endl;
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro una cancion con el id " << idCancion << " dentro la base de datos" << endl;
                }
                if (!bandera2)
                {
                    cout << "Esta cancion no tiene me gusta" << endl;
                }
                system("pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                system("CLS");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
                system("pause");
            }
        }
    }while (opcion != 3);
}
void modificarPlaylist (ListaReproduccion listas [],int tam,int& contListas,int& cantCanciones2)
{
    int opcion, idPlayList, tamAux;
    string nombreCancion, nombreCancionAux;
    bool bandera = false;
    bool bandera2 = false;

    do
    {
        system("CLS");
        cout << "1. Agregar una cancion" << endl;
        cout << "2. Eliminar una cancion" << endl;
        cout << "3. Volver al menu anterior" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                system("CLS");
                cout << "Por favor digite el id de la PlayList a la cual le quiere agregar una cancion: ";
                cin >> idPlayList;

                for (int i = 0; i < contListas; i++)
                {
                    if (idPlayList == stoi(listas[i].id))
                    {
                        bandera = true;
                        cin.ignore(1);
                        cout << "Por favor digite el nombre de la cancion que quiere agregar: ";
                        getline(cin,nombreCancion);
                        listas[i].cantCanciones++;

                        if(listas[i].cantCanciones < tam)
                        {
                            listas[i].listaCanciones[listas[i].cantCanciones - 1] = nombreCancion;
                            cout << "Modificacion realizada exitosamente" << endl << endl;
                            impresionPlayList(listas,contListas);
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro una PlayList con el id " << idPlayList << " en la base de datos" << endl;
                }
                system("pause");
                break;
            }
            case 2:
            {
                system("CLS");
                cout << "Por favor digite el id de la PlayList a la cual le quiere eliminar una cancion: ";
                cin >> idPlayList;

                for (int i = 0; i < contListas; i++)
                {
                    if (idPlayList == stoi(listas[i].id))
                    {
                        bandera = true;
                        cin.ignore(1);
                        cout << "Por favor digite el nombre de la cancion que quiere eliminar: ";
                        getline(cin,nombreCancion);

                        for (int j = 0; j < listas[i].cantCanciones; j++)
                        {
                            if (nombreCancion == listas[i].listaCanciones[j])
                            {
                                bandera2 = true;
                                listas[i].cantCanciones--;

                                if(listas[i].cantCanciones < tam)
                                {
                                    listas[i].listaCanciones[j] = "";
                                    cout << "Modificacion realizada exitosamente" << endl << endl;
                                    impresionPlayList(listas,contListas);
                                }
                            }
                        }
                    }
                }
                if (!bandera)
                {
                    cout << "No se encontro una PlayList con el id " << idPlayList << " en la base de datos" << endl;
                }
                if (!bandera2)
                {
                    cout << "No se encontro la cancion con el nombre " << nombreCancion << " dentro de la playList con id " << idPlayList << endl;
                }

                system("pause");
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                system("CLS");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
                system("pause");
            }
        }
    }while (opcion != 3);
}
void menuModificarInformacion ()
{
    int opcion = 0;

    do
    {
        system("cls");
        cout << " --------------------------------- MENU MODIFICAR INFORMACION --------------------------------- " << endl;
        cout << "1. Modificar un artista" << endl;
        cout << "2. Modificar un album" << endl;
        cout << "3. Modificar una cancion" << endl;
        cout << "4. Modificar una PlayList" << endl;
        cout << "5. Volver al menu princial" << endl;
        cout << "Por favor seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                system("CLS");
                modificarArtista (artistas,contArtistas,cantAlb,tam);
                system("Pause");
                break;
            }
            case 2:
            {
                system("CLS");
                modificarAlbum (albumes,contAlbumes,cantCanciones,tam);
                system("Pause");
                break;
            }
            case 3:
            {
                system("CLS");
                modificarCancion (canciones,contCanciones);
                system("Pause");
                break;
            }
            case 4:
            {
                system("CLS");
                modificarPlaylist (listas,tam,contListas,cantCanciones2);
                system("Pause");
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    } while (opcion != 5);
}


void menuPrincipal ()
{
    int opcion = 0;
    do
    {
        system("CLS");
        cout << " --------------------------------- MENU SPOTIFY PUJ --------------------------------- " << endl;
        cout << "1. Ingresar Informacion" << endl;
        cout << "2. Modificar Informacion" << endl;
        cout << "3. Buscar Informacion" << endl;
        cout << "4. Imprimir Informacion" << endl;
        cout << "5. Salir de la Aplicacion" << endl;
        cout << "Por favor seleccione su opcion: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1:
            {
                system ("cls");
                menuTipoCarga();
                system ("Pause");
                break;
            }
            case 2:
            {
                system ("CLS");
                menuModificarInformacion();
                system ("Pause");
                break;
            }
            case 3:
            {
                system ("CLS");
                menuBusquedaInformacion();
                system ("Pause");
                break;
            }
            case 4:
            {
                system ("CLS");
                menuImprimir();
                system ("Pause");
                break;
            }
            case 5:
            {
                system ("CLS");
                cout << "Muchas gracias por haber utilizado el programa SPOTITY PUJ" << endl;
                cout << "Esperamos vuelva pronto!" << endl;
                system ("Pause");
                break;
            }
            default:
            {
                system ("CLS");
                cout << "Selecciono una opcion incorrecta. Por favor digite una opcion valida" << endl;
            }
        }
    }while (opcion != 5);
}