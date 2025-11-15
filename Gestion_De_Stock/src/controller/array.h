#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

template <typename T>
/**
 * @brief Clase dinámica de arreglos genérica.
 *
 * Esta clase administra un arreglo dinámico de elementos de tipo T,
 * proporcionando operaciones básicas de acceso, inserción, eliminación
 * y redimensionamiento.
 *
 * @tparam T Tipo de los elementos almacenados en el array.
 */
class Array {
private:
    /** @brief Número de elementos actualmente almacenados en el arreglo. */
    unsigned int size;

    /** @brief Puntero al bloque dinámico que contiene los elementos de tipo T. */
    T* elements;

    /**
     * @brief Crea un nuevo registro a partir de @p node (uso interno).
     * @param node Referencia al objeto que se desea crear/copiar.
     * @return true si la creación fue exitosa, false en caso contrario.
     */
    bool CreateRecord(T& node);

    /**
     * @brief Devuelve una copia del elemento ubicado en @p index.
     * @param index Índice del elemento a leer.
     * @return Copia del elemento en @p index.
     * @note La firma actual usa un marcador <T> que puede ser sintácticamente inválido;
     *       conservar según la implementación existente.
     */
    <T> ReadRecord(unsigned int index);

    /**
     * @brief Actualiza el registro en la posición @p index con los datos de @p node.
     * @param index Índice del elemento a actualizar.
     * @param node Referencia con los nuevos datos.
     * @return true si la actualización fue exitosa.
     */
    bool UpdateRecord(unsigned int index, T& node);

    /**
     * @brief Elimina el registro en la posición @p index.
     * @param index Índice del elemento a eliminar.
     * @return true si la eliminación fue exitosa.
     */
    bool DeleteRecord(unsigned int index);

    /**
     * @brief Redimensiona la estructura a @p newSize elementos.
     * @param newSize Nueva capacidad deseada.
     * @return true si la redimensión se realizó correctamente.
     */
    bool ReSizing(unsigned int newSize);

public:
    /** @brief Constructor: inicializa un Array vacío. */
    Array();

    /** @brief Destructor: libera la memoria utilizada por el array. */
    ~Array();
    
    /**
     * @brief Compara @p node con elementos del array.
     * @param node Referencia al nodo a comparar.
     * @return true si existe una coincidencia, false en caso contrario.
     */
    bool operator==(T& node);

    /**
     * @brief Inserta o combina @p node con la estructura (comportamiento según implementación).
     * @param node Referencia al nodo a insertar o combinar.
     * @return true si la operación tuvo éxito.
     */
    bool operator+(T& node);

    /**
     * @brief Acceso por índice: devuelve referencia al elemento en @p index.
     * @param index Índice del elemento.
     * @return Referencia al elemento en @p index.
     * @note La firma actual usa un marcador <T>& que puede ser sintácticamente inválido;
     *       conservar según la implementación existente.
     */
    <T>& operator[](unsigned int index);

    /**
     * @brief Asignación o reemplazo mediante operador '=' (detalles en implementación).
     * @param node Referencia al nodo a asignar.
     * @return true si la operación fue exitosa.
     */
    bool operator=(T& node);

    /**
     * @brief Elimina o resta @p node de la estructura (comportamiento según implementación).
     * @param node Referencia al nodo a eliminar.
     * @return true si la operación fue exitosa.
     */
    bool operator-(T& node);

    /**
     * @brief Devuelve la cantidad de elementos actualmente almacenados.
     * @return Número de elementos en el array.
     */
    int Count();

    /**
     * @brief Elimina el elemento en la posición @p index.
     * @param index Índice del elemento a eliminar.
     * @return true si se eliminó correctamente.
     */
    bool RemoveAt(unsigned int index);

    /**
     * @brief Inserta @p node en la posición @p index.
     * @param index Índice donde insertar.
     * @param node Referencia al nodo a insertar.
     * @return true si la inserción tuvo éxito.
     */
    bool InsertAt(unsigned int index, T& node);

    /**
     * @brief Agrega @p node al final del array.
     * @param node Referencia al nodo a agregar.
     * @return true si se agregó correctamente.
     */
    bool Append(T& node);

    /**
     * @brief Limpia todos los elementos del array y libera la memoria asociada.
     * @return true si la operación fue exitosa.
     */
    bool Clear();
};

#endif // ARRAY_H
