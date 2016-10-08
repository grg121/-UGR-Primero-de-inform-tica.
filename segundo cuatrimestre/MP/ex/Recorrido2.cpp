#include"Recorrido2.h"


Punto GetPosicion(double seed){
  Punto nuevo(0.75 * seed + 4/seed, 0.9*(seed + 1), seed/3 + 4/seed) ;
  return nuevo ;
}

Instante GetInstante(int seed){
  Hora h((seed*5)%12, (seed*100)%60, (11*seed+1)%60) ;
  Fecha f(23, 03, 2017) ;
  Instante nuevo(f,h) ;
  return nuevo ;
}

void Recorrido::AgregarPunto(PuntoDeRecorrido &punto){
  if(activo){
  PuntoDeRecorrido *aux = new PuntoDeRecorrido[num_puntos + 1] ;
  for(int i = 0 ; i < num_puntos ; i++)
    aux[i] = puntos[i] ;
  if(puntos != NULL) delete [] puntos ;
  puntos = aux ;
  num_puntos++ ;
} else return 1 ;
}


  Recorrido::Recorrido(bool iniciar){
    puntos = NULL ;
    num_puntos = 0 ;
    activo = true ;

    if(iniciar){
      PuntoDeRecorrido nuevo ;
      nuevo.punto = GetPosicion() ;
      nuevo.instante = GetInstante() ;
      AgregarPunto(nuevo) ;
    }
  }

  Recorrido::~Recorrido(){
    delete [] puntos ;
  }

  void Recorrido::Swap(Recorrido & otro){
    Recorrido aux ;
    aux.puntos = otro.puntos ;
    aux.num_puntos = otro.num_puntos ;
    aux.activo = otro.activo ;

    otro.puntos = this.puntos ;
    otro.num_puntos = this.num_puntos ;
    otro.activo = this.activo ;

    this.puntos = aux.puntos ;
    this.activo = aux.activo ;
    this.num_puntos = aux.num_puntos ;
  }

  Recorrido::Recorrido(const Recorrido & original){
    if(puntos != NULL) delete [] puntos ;
    this.num_puntos = original.num_puntos ;
    this.activo = original.activo ;
    this.puntos = new PuntoDeRecorrido[this.num_puntos] ;
    for(int i = 0 ; i < this.num_puntos ; i++){
      this.puntos[i] = original.puntos[i] ;
    }
  }

  Recorrido &Recorrido::operator=(const Recorrido & original){
    if(this.puntos != NULL && this != &original) delete [] puntos ;
    Recorrido copia(original) ;
    this.Swap(copia) ;
  }





  void Recorrido::FinDeRecorrido(){
    PuntoDeRecorido nuevo ;
    nuevo.punto = GetPosicion(10) ;
    nuevo.instante = GetInstante(11) ;
 }

 double Recorrido::DistanciaRecorrido() const {
     double distancia = 0;
     for(int i=1; i<num_puntos; i++)
         distancia += puntos[i].punto.DistanciaAPunto(puntos[i-1].punto);
     return distancia;
 }

 double Recorrido::TiempoRecorrido() const {
     double tiempo = 0;
     for(int i=1; i<num_puntos; i++)
         tiempo += puntos[i-1].instante.IntervaloTiempo(puntos[i].instante);
     return tiempo;
 }

 double Recorrido::VelocidadMedia() const {
     return (DistanciaRecorrido()/1000)/(TiempoRecorrido()/3600);
 }



 std::ostream &operator<<(std::ostream &flujo, const Recorrido &r) {
     if (r.num_puntos > 0) {
         flujo <<
         // Primera linea
         r.puntos[0].instante.getFecha().getDia() << " " <<
         r.puntos[0].instante.getFecha().getMes() << " " <<
         r.puntos[0].instante.getFecha().getAnio() << "\n" <<
         // Segunda linea
         r.puntos[0].instante.getHora().getHora() << " " <<
         r.puntos[0].instante.getHora().getMinuto() << " " <<
         r.puntos[0].instante.getHora().getSegundo() << "\n" <<
         // Tercera linea
         r.puntos[r.num_puntos - 1].instante.getFecha().getDia() << " " <<
         r.puntos[r.num_puntos - 1].instante.getFecha().getMes() << " " <<
         r.puntos[r.num_puntos - 1].instante.getFecha().getAnio() << "\n" <<
         // Cuarta linea
         r.puntos[r.num_puntos - 1].instante.getHora().getHora() << " " <<
         r.puntos[r.num_puntos - 1].instante.getHora().getMinuto() << " " <<
         r.puntos[r.num_puntos - 1].instante.getHora().getSegundo() << "\n" <<
         // Quinta linea
         r.num_puntos;

         // Lista de puntos
         for (int i = 0; i < r.num_puntos; i++) {
             flujo << "\n" <<
             r.puntos[i].punto.getLongitud() << " " <<
             r.puntos[i].punto.getLatitud() << " " <<
             r.puntos[i].punto.getAltura() << " " <<
             r.puntos[i].instante.getFecha().getDia() << " " <<
             r.puntos[i].instante.getFecha().getMes() << " " <<
             r.puntos[i].instante.getFecha().getAnio() << " " <<
             r.puntos[i].instante.getHora().getHora() << " " <<
             r.puntos[i].instante.getHora().getMinuto() << " " <<
             r.puntos[i].instante.getHora().getSegundo();
         }
     }

     return flujo;
 }

 std::istream &operator>>(std::istream &flujo, Recorrido &r) {
     Recorrido resultado(false);
     std::string s;
     int n_puntos;

     // Saltar primeras 4 lineas
     getline(flujo, s);
     getline(flujo, s);
     getline(flujo, s);
     getline(flujo, s);

     // Numero de puntos
     flujo >> n_puntos;

     // Lista de puntos
     for(int i=0; i<n_puntos; i++) {

         int dia, mes, anio, hora, minuto, segundo;
         double lon, lat, alt;

         flujo >> lon >> lat >> alt;
         flujo >> dia >> mes >> anio >> hora >> minuto >> segundo;

         if(flujo) {
             // Añadimos el nuevo punto en caso de que las lecturas hayan sido correctas
             PuntoDeRecorrido puntoDeRecorrido;

             Punto p(lat, lon, alt);
             Hora h(hora, minuto, segundo);
             Fecha f(dia, mes, anio);
             Instante inst(f, h);

             puntoDeRecorrido.punto = p;
             puntoDeRecorrido.instante = inst;

             resultado.anadirPunto(puntoDeRecorrido);
         } else {
             // Terminamos la lectura en caso de que haya habido un error en el fichero
             break;
         }
     }

     r = resultado;

     return flujo;
 }

 bool Recorrido::escritura(const char *fichero) {
     std::ofstream f(fichero, std::ios::out);
     if(f) {
         f << *this;
     }
     return !f.fail();
 }

 /* Version alternativa de Recorrido::escritura que no utiliza el operador sobrecargado << */
 bool Recorrido::escritura2(const char *fichero) {
     std::ofstream f(fichero, std::ios::out);
     if(f) {
         if (this->num_puntos > 0) {
             f <<
             // Primera linea
             this->puntos[0].instante.getFecha().getDia() << " " <<
             this->puntos[0].instante.getFecha().getMes() << " " <<
             this->puntos[0].instante.getFecha().getAnio() << "\n" <<
             // Segunda linea
             this->puntos[0].instante.getHora().getHora() << " " <<
             this->puntos[0].instante.getHora().getMinuto() << " " <<
             this->puntos[0].instante.getHora().getSegundo() << "\n" <<
             // Tercera linea
             this->puntos[this->num_puntos - 1].instante.getFecha().getDia() << " " <<
             this->puntos[this->num_puntos - 1].instante.getFecha().getMes() << " " <<
             this->puntos[this->num_puntos - 1].instante.getFecha().getAnio() << "\n" <<
             // Cuarta linea
             this->puntos[this->num_puntos - 1].instante.getHora().getHora() << " " <<
             this->puntos[this->num_puntos - 1].instante.getHora().getMinuto() << " " <<
             this->puntos[this->num_puntos - 1].instante.getHora().getSegundo() << "\n" <<
             // Quinta linea
             this->num_puntos;

             // Lista de puntos
             for (int i = 0; i < this->num_puntos; i++) {
                 f << "\n" <<
                 this->puntos[i].punto.getLongitud() << " " <<
                 this->puntos[i].punto.getLatitud() << " " <<
                 this->puntos[i].punto.getAltura() << " " <<
                 this->puntos[i].instante.getFecha().getDia() << " " <<
                 this->puntos[i].instante.getFecha().getMes() << " " <<
                 this->puntos[i].instante.getFecha().getAnio() << " " <<
                 this->puntos[i].instante.getHora().getHora() << " " <<
                 this->puntos[i].instante.getHora().getMinuto() << " " <<
                 this->puntos[i].instante.getHora().getSegundo();
             }
         }
     }
     return !f.fail();
 }

 /* Version alternativa de Recorrido::escritura que realiza escritura binaria */
 bool Recorrido::escrituraBin(const char *fichero) {
     std::ofstream f(fichero, std::ios::out | std::ios::binary);
     if(f) {
         if (this->num_puntos > 0) {
             int dia, mes, anio, hora, minuto, segundo;
             double lon_lat_alt[3];

             // Instante inicial
             dia = this->puntos[0].instante.getFecha().getDia();
             f.write(reinterpret_cast<char *>(&dia), sizeof(int));
             mes = this->puntos[0].instante.getFecha().getMes();
             f.write(reinterpret_cast<char *>(&mes), sizeof(int));
             anio = this->puntos[0].instante.getFecha().getAnio();
             f.write(reinterpret_cast<char *>(&anio), sizeof(int));

             hora = this->puntos[0].instante.getHora().getHora();
             f.write(reinterpret_cast<char *>(&hora), sizeof(int));
             minuto = this->puntos[0].instante.getHora().getMinuto();
             f.write(reinterpret_cast<char *>(&minuto), sizeof(int));
             segundo = this->puntos[0].instante.getHora().getSegundo();
             f.write(reinterpret_cast<char *>(&segundo), sizeof(int));

             // Instante final
             dia = this->puntos[this->num_puntos - 1].instante.getFecha().getDia();
             f.write(reinterpret_cast<char *>(&dia), sizeof(int));
             mes = this->puntos[this->num_puntos - 1].instante.getFecha().getMes();
             f.write(reinterpret_cast<char *>(&mes), sizeof(int));
             anio = this->puntos[this->num_puntos - 1].instante.getFecha().getAnio();
             f.write(reinterpret_cast<char *>(&anio), sizeof(int));

             hora = this->puntos[this->num_puntos - 1].instante.getHora().getHora();
             f.write(reinterpret_cast<char *>(&hora), sizeof(int));
             minuto = this->puntos[this->num_puntos - 1].instante.getHora().getMinuto();
             f.write(reinterpret_cast<char *>(&minuto), sizeof(int));
             segundo = this->puntos[this->num_puntos - 1].instante.getHora().getSegundo();
             f.write(reinterpret_cast<char *>(&segundo), sizeof(int));

             // Numero de puntos
             f.write(reinterpret_cast<char *>(&this->num_puntos), sizeof(int));

             // Lista de puntos
             for (int i = 0; i < this->num_puntos; i++) {

                 lon_lat_alt[0] = this->puntos[i].punto.getLongitud();
                 lon_lat_alt[1] = this->puntos[i].punto.getLatitud();
                 lon_lat_alt[2] = this->puntos[i].punto.getAltura();
                 f.write(reinterpret_cast<char *>(lon_lat_alt), sizeof(double) * 3);     // En lugar de escribir los valores 1 a 1, utilizamos un array y escribimos un bloque de 3 valores double

                 dia = this->puntos[i].instante.getFecha().getDia();
                 f.write(reinterpret_cast<char *>(&dia), sizeof(int));
                 mes = this->puntos[i].instante.getFecha().getMes();
                 f.write(reinterpret_cast<char *>(&mes), sizeof(int));
                 anio = this->puntos[i].instante.getFecha().getAnio();
                 f.write(reinterpret_cast<char *>(&anio), sizeof(int));

                 hora = this->puntos[i].instante.getHora().getHora();
                 f.write(reinterpret_cast<char *>(&hora), sizeof(int));
                 minuto = this->puntos[i].instante.getHora().getMinuto();
                 f.write(reinterpret_cast<char *>(&minuto), sizeof(int));
                 segundo = this->puntos[i].instante.getHora().getSegundo();
                 f.write(reinterpret_cast<char *>(&segundo), sizeof(int));

             }
         }
     }
     return !f.fail();
 }

 bool Recorrido::lectura(const char *fichero) {
     std::ifstream f(fichero, std::ios::in);
     if(f) {
         f >> *this;
     }
     return !f.fail();
 }

 /* Version alternativa de Recorrido::lectura que no utiliza el operador sobrecargado >> */
 bool Recorrido::lectura2(const char *fichero) {
     std::ifstream f(fichero, std::ios::in);
     if(f) {
         Recorrido resultado(false);
         std::string s;
         int n_puntos;

         // Saltar primeras 4 lineas
         getline(f, s);
         getline(f, s);
         getline(f, s);
         getline(f, s);

         // Numero de puntos
         f >> n_puntos;

         // Lista de puntos
         for(int i=0; i<n_puntos; i++) {

             int dia, mes, anio, hora, minuto, segundo;
             double lon, lat, alt;

             f >> lon >> lat >> alt;
             f >> dia >> mes >> anio >> hora >> minuto >> segundo;

             if(f) {
                 // Añadimos el nuevo punto en caso de que las lecturas hayan sido correctas
                 PuntoDeRecorrido puntoDeRecorrido;

                 Punto p(lat, lon, alt);
                 Hora h(hora, minuto, segundo);
                 Fecha f(dia, mes, anio);
                 Instante inst(f, h);

                 puntoDeRecorrido.punto = p;
                 puntoDeRecorrido.instante = inst;

                 resultado.anadirPunto(puntoDeRecorrido);
             } else {
                 // Terminamos la lectura en caso de que haya habido un error en el fichero
                 break;
             }
         }

         (*this) = resultado;
     }
     return !f.fail();
 }

 /* Version alternativa de Recorrido::lectura que realiza lectura binaria */
 bool Recorrido::lecturaBin(const char *fichero) {
     std::ifstream f(fichero, std::ios::in | std::ios::binary);
     if(f) {
         Recorrido resultado(false);
         std::string s;
         int n_puntos;

         // Saltar 12 primeros valores enteros (instantes del punto inicial y final del recorrido)
         f.seekg(12* sizeof(int));

         // Numero de puntos
         f.read(reinterpret_cast<char *>(&n_puntos), sizeof(int));

         // Lista de puntos
         for(int i=0; i<n_puntos; i++) {

             int dia, mes, anio, hora, minuto, segundo;
             double lon_lat_alt[3], lon, lat, alt;

             f.read(reinterpret_cast<char *>(lon_lat_alt), sizeof(double)*3);    // Lectura en bloque de tres valores
             lon = lon_lat_alt[0];
             lat = lon_lat_alt[1];
             alt = lon_lat_alt[2];

             f.read(reinterpret_cast<char *>(&dia), sizeof(int));                // Lectura de valores individuales
             f.read(reinterpret_cast<char *>(&mes), sizeof(int));
             f.read(reinterpret_cast<char *>(&anio), sizeof(int));
             f.read(reinterpret_cast<char *>(&hora), sizeof(int));
             f.read(reinterpret_cast<char *>(&minuto), sizeof(int));
             f.read(reinterpret_cast<char *>(&segundo), sizeof(int));

             if(f) {
                 // Añadimos el nuevo punto en caso de que las lecturas hayan sido correctas
                 PuntoDeRecorrido puntoDeRecorrido;

                 Punto p(lat, lon, alt);
                 Hora h(hora, minuto, segundo);
                 Fecha f(dia, mes, anio);
                 Instante inst(f, h);

                 puntoDeRecorrido.punto = p;
                 puntoDeRecorrido.instante = inst;

                 resultado.anadirPunto(puntoDeRecorrido);
             } else {
                 // Terminamos la lectura en caso de que haya habido un error en el fichero
                 break;
             }
         }

         (*this) = resultado;
     }
     return !f.fail();

 }



 PuntoDeRecorrido &Recorrido::operator[](int i) {
     assert(i >= 0);
     assert(i < num_puntos);
     return puntos[i];
 }

 const PuntoDeRecorrido &Recorrido::operator[](int i) const {
     assert(i >= 0);
     assert(i < num_puntos);
     return puntos[i];
 }


 Recorrido generarRecorridoAleatorio() {
     Recorrido r(true);
     int n = rand() % 6;

     for(int i=0; i<n; i++) {
         Punto p = GetPosicion();
         Punto pVariacion(p.getLatitud() + rand() % 2, p.getLongitud() + rand() % 2, p.getAltura());

         std::this_thread::sleep_for(std::chrono::seconds(1));
         Instante instVariacion = GetInstante();

         PuntoDeRecorrido puntoDeRecorrido;
         puntoDeRecorrido.punto = pVariacion;
         puntoDeRecorrido.instante = instVariacion;

         r.anadirPunto(puntoDeRecorrido);
     }

     r.FinRecorrido();

     return r;

  }
