#ifndef TIPORESPONSABLE_H
#define TIPORESPONSABLE_H


class TipoResponsable
{
    public:
        /** Default constructor */
        TipoResponsable();
        /** Default destructor */
        virtual ~TipoResponsable();

        /** Access m_Id
         * \return The current value of m_Id
         */
        unsigned int GetId() { return m_Id; }

    protected:

    private:
        unsigned int m_Id; //!< Member variable "m_Id"
};

#endif // TIPORESPONSABLE_H
