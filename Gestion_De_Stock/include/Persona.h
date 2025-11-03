#ifndef PERSONA_H
#define PERSONA_H

class Persona {
    public:
        /** Default constructor */
        Persona();
        /** Default destructor */
        virtual ~Persona();

    protected:
        /** Access m_DNI
         * \return The current value of m_DNI
         */
        unsigned int GetDNI() { return m_DNI; }
        /** Access m_Nombre[20]
         * \return The current value of m_Nombre[20]
         */
        char GetNombre[20]() { return m_Nombre[20]; }
        /** Access m_Apellido[20]
         * \return The current value of m_Apellido[20]
         */
        char GetApellido[20]() { return m_Apellido[20]; }
        /** Access m_Telefono[15]
         * \return The current value of m_Telefono[15]
         */
        void SetTelefono(const char[15] val) { m_Telefono = val; }
        /** Access m_Telefono[15]
         * \return The current value of m_Telefono[15]
         */
        char GetTelefono[15]() { return m_Telefono[15]; }
        /** Access m_Celular[15]
         * \return The current value of m_Celular[15]
         */
        void SetCelular(const char[15] val) { m_Celular = val; }
        /** Access m_Celular[15]
         * \return The current value of m_Celular[15]
         */
        char GetCelular[15]() { return m_Celular[15]; }

        const unsigned int m_DNI; //!< Member variable "m_DNI"
        char m_Nombre[20]; //!< Member variable "m_Nombre[20]"
        char m_Apellido[20]; //!< Member variable "m_Apellido[20]"
        char m_Telefono[15]; //!< Member variable "m_Telefono[15]"
        char m_Celular[15]; //!< Member variable "m_Celular[15]"
};

#endif // PERSONA_H
