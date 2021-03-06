
/* 
 * File:   Temazo.cpp
 * Author: Alberto Limas
 * 
 * Created on 21 de junio de 2020, 20:41
 */

#include "Temazo.h"

int Temazo::_numTemazos = 0;

Temazo::Temazo() {
    string _titulo="";
    string _interprete="";
    int _duracion=0;
    int _puntuacion=0;
    string _nombreUltimoGarito="";
    Fecha _fechaUltimoUso=Fecha();
    
    int _idTemazo=_numTemazos;
    _numTemazos++;
}


Temazo::Temazo(string titulo, string interprete, int duracion, string nombreUltimoGarito, Fecha fechaUltimoUso, int puntuacion):
_titulo(titulo),_interprete(interprete),_duracion(duracion),_nombreUltimoGarito(nombreUltimoGarito),_fechaUltimoUso(fechaUltimoUso) ,_puntuacion(puntuacion){
    
    _idTemazo=_numTemazos;
    _numTemazos++;
}


Temazo::Temazo(const Temazo& orig):
_titulo(orig._titulo),_interprete(orig._interprete),_duracion(orig._duracion),
        _nombreUltimoGarito(orig._nombreUltimoGarito),_fechaUltimoUso(orig._fechaUltimoUso),_puntuacion(orig._puntuacion) {
    
    _idTemazo=_numTemazos;
    _numTemazos++;
}

Temazo::~Temazo() {
}

int Temazo::GetPuntuacion() const {
    return _puntuacion;
}

void Temazo::SetDuracion(int _duracion) {
    this->_duracion = _duracion;
}

int Temazo::GetDuracion() const {
    return _duracion;
}

void Temazo::SetInterprete(string _interprete) {
    this->_interprete = _interprete;
}

string Temazo::GetInterprete() const {
    return _interprete;
}

void Temazo::SetTitulo(string _titulo) {
    this->_titulo = _titulo;
}

string Temazo::GetTitulo() const {
    return _titulo;
}

void Temazo::SetFechaUltimoUso(Fecha _fechaUltimoUso) {
    this->_fechaUltimoUso = _fechaUltimoUso;
}

Fecha Temazo::GetFechaUltimoUso() const {
    return _fechaUltimoUso;
}

void Temazo::SetNombreUltimoGarito(string _nombreUltimoGarito) {
    this->_nombreUltimoGarito = _nombreUltimoGarito;
}

string Temazo::GetNombreUltimoGarito() const {
    return _nombreUltimoGarito;
}

void Temazo::incrementarPuntuacion(int puntuacion) {
    if(puntuacion < -10 || puntuacion > 10){
        throw ParametroNoValido("Temazo.cpp","Temazo::incrementarPuntuacion","Puntuación fuera rango [-10,10]");
    }
    else{
        this->_puntuacion+=puntuacion;
    }
}

int Temazo::GetIdTemazo() const {
    return _idTemazo;
}

string Temazo::toCSV() {
    std::stringstream ss;
    
    /*ss << _idTemazo << ";" << _titulo << ";" << _interprete << ";" << _duracion << ";" << _puntuacion << ";" << _nombreUltimoGarito << ";" << 
            _fechaUltimoUso.GetDia() << "," << _fechaUltimoUso.GetMes() << "," << _fechaUltimoUso.GetYear() ;*/
    
    ss << _idTemazo << ";" << _titulo << ";" << _interprete << ";" << _duracion << ";" << _puntuacion << ";" << _nombreUltimoGarito << ";" << 
            _fechaUltimoUso.toCSV() ;
    
    return ss.str();
}
