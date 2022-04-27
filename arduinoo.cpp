#include "arduinoo.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
Arduinoo::Arduinoo()
{
    data="";
    Arduinoo_port_name="";
    Arduinoo_is_available=false;
    serial=new QSerialPort;
}

QString Arduinoo::getArduinoo_port_name()
{
    return Arduinoo_port_name;
}

QSerialPort *Arduinoo::getserial()
{
   return serial;
}
int Arduinoo::connect_Arduinoo()
{   // recherche du port sur lequel la carte Arduinoo identifée par  Arduinoo_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == Arduinoo_uno_vendor_id && serial_port_info.productIdentifier()
                       == Arduinoo_uno_producy_id) {
                   Arduinoo_is_available = true;
                   Arduinoo_port_name=serial_port_info.portName();
               } } }
        qDebug() << "Arduinoo_port_name is :" << Arduinoo_port_name;
        if(Arduinoo_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(Arduinoo_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduinoo::close_Arduinoo()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduinoo::read_from_Arduinoo()
{

    if(serial->isReadable()){
        serial->waitForReadyRead(10);
         data=serial->readAll();
         return data;
    }
 }

int Arduinoo::write_to_Arduinoo(QByteArray d)
{ if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduinoo
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
