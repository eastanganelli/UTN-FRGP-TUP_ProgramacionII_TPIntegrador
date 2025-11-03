#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente : public Persona {
    public:
        /** Default constructor */
        Cliente();
        /** Default destructor */
        virtual ~Cliente();

        /** Access m_Id
         * \return The current value of m_Id
         */
        const unsigned int GetId() { return m_Id; }
        /** Set m_Id
         * \param val New value to set
         */
        void SetId(const unsigned int val) { m_Id = val; }
        /** Access m_Correo[70]
         * \return The current value of m_Correo[70]
         */
        char GetCorreo[70]() { return m_Correo[70]; }
        /** Set m_Correo[70]
         * \param val New value to set
         */
        void SetCorreo[70](char val) { m_Correo[70] = val; }
        /** Access m_CuilCuit[15]
         * \return The current value of m_CuilCuit[15]
         */
        char GetCuilCuit[15]() { return m_CuilCuit[15]; }
        /** Access m_Alta
         * \return The current value of m_Alta
         */
        bool GetAlta() { return m_Alta; }
        /** Set m_Alta
         * \param val New value to set
         */
        void SetAlta(bool val) { m_Alta = val; }

    protected:

    private:
        const unsigned int m_Id; //!< Member variable "m_Id"
        char m_Correo[70]; //!< Member variable "m_Correo[70]"
        char m_CuilCuit[15]; //!< Member variable "m_CuilCuit[15]"
        bool m_Alta; //!< Member variable "m_Alta"
};

#endif // CLIENTE_H
