#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        /** Default constructor */
        Fecha();
        /** Default destructor */
        virtual ~Fecha();

        /** Access m_Dia
         * \return The current value of m_Dia
         */
        unsigned int GetDia() { return m_Dia; }
        /** Access m_Mes
         * \return The current value of m_Mes
         */
        unsigned int GetMes() { return m_Mes; }
        /** Access m_Anio
         * \return The current value of m_Anio
         */
        unsigned int GetAnio() { return m_Anio; }

    protected:

    private:
        unsigned int m_Dia; //!< Member variable "m_Dia"
        unsigned int m_Mes; //!< Member variable "m_Mes"
        unsigned int m_Anio; //!< Member variable "m_Anio"
};

#endif // FECHA_H
