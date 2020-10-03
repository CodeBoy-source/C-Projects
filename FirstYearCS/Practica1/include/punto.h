#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    /**
     * Coordenada x
     */
    double x;
    /**
     * Coordenada y
     */
    double y;

public:

    /**
     * Constructor por defecto: pondra a 0 el valor de las
     * coordenadas. A implementar
     */
    Punto() {
        x = 0;
        y = 0;
    }

    /**
     * Constructor que permite asignar valor a los datos miembro.
     * A implementar
     * @param vx
     * @param vy
     */
    Punto(double vx, double vy) {
        x = vx;
        y = vy;
    }

    /**
     * Metodo de acceso al dato miembro x. A implementar
     * @return
     */
    double getX() const {
        return x;
    }

    /**
     * Metodo de acceso al dato miembro y. A implementar
     * @return
     */
    double getY() const {
        return y;
    }

    /**
     * Metodo para asignar valor al dato miembro x. A implementar
     * @param vx
     */
    void setX(double vx) {
        x = vx;
    }

    /**
     * Metodo para asignar valor al dato miembro Y. A implementar
     * @param vy
     */
    void setY(double vy) {
        y = vy;
    }

    /**
     * Muestra el contenido del objeto por pantalla. A implementar
     * fuera del ambito de declaracion de la clase. Por eso aparece
     * aqui unicamente la declaracion
     */
    void mostrar_punto() const;

    /**
     * Metodo para preguntar los valores de los datos miembro al
     * usuario. Por implementar, fuera del ambito de la clase
     */
    void leerDatos();
};

#endif