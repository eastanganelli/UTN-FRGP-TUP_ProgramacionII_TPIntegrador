#ifndef FILESYSTEM_H
#define FILESYSTEM_H

using namespace std;

template <typename T>
class FileSystem {
private:
    /** @brief Ruta del archivo que gestiona este FileSystem. */
    const string filePath;

    /** @brief Contador estático de registros (uso dependiendo de la implementación).
     *
     * @note Este miembro es estático y comparte su valor entre todas las instancias
     *       de `FileSystem<T>`.
     */
    static unsigned int counter;

    /**
     * @brief Busca la posición de @p record en el almacenamiento.
     * @param record Referencia al registro a buscar.
     * @param index Referencia donde se devolverá el índice si se encuentra.
     * @return true si se encontró el registro y se estableció @p index.
     */
    bool IndexOf(T& record, unsigned int& index);

    /**
     * @brief Crea un nuevo registro en el almacenamiento a partir de @p record.
     * @param record Referencia al registro a crear.
     * @return true si la creación fue exitosa.
     */
    bool CreateRecord(T& record);

    /**
     * @brief Lee y devuelve el registro en la posición @p index.
     * @param index Índice del registro a leer.
     * @return Copia del registro leído.
     * @note La firma actual utiliza un marcador `<T>` que puede no ser sintácticamente
     *       estándar en C++; se conserva aquí según la implementación existente.
     */
    <T> ReadRecord(unsigned int index);

    /**
     * @brief Actualiza el registro en la posición @p index con los datos de @p record.
     * @param index Índice del registro a actualizar.
     * @param record Referencia con los nuevos datos.
     * @return true si la actualización fue exitosa.
     */
    bool UpdateRecord(unsigned int index, T& record);

    /**
     * @brief Elimina el registro en la posición @p index.
     * @param index Índice del registro a eliminar.
     * @return true si la eliminación fue exitosa.
     */
    bool DeleteRecord(unsigned int index);

public:
    /**
     * @brief Construye un FileSystem asociado a la ruta @p _filePath.
     * @param _filePath Ruta del archivo a gestionar.
     */
    FileSystem(const string& _filePath);

    /** @brief Destructor: realiza limpieza necesaria al destruir la instancia. */
    ~FileSystem();

    /**
     * @brief Devuelve el último registro almacenado.
     * @return Último registro.
     * @note Firma conservada con marcador `<T>` según la implementación actual.
     */
    <T> LastRegistry();

    /**
     * @brief Lista todos los registros almacenados.
     * @return Estructura/colección con todos los registros.
     * @note Firma conservada con marcador `<T>` según la implementación actual.
     */
    <T> ListAll();

    /**
     * @brief Comprueba si @p record existe en el almacenamiento.
     * @param record Referencia al registro a comprobar.
     * @return true si existe una coincidencia.
     */
    bool operator==(T& record);

    /**
     * @brief Inserta o agrega @p record al almacenamiento (según implementación).
     * @param record Referencia al registro a insertar.
     * @return true si la operación tuvo éxito.
     */
    bool operator+(T& record);

    /**
     * @brief Acceso por índice para leer un registro.
     * @param index Índice del registro.
     * @return Registro en la posición @p index.
     * @note Firma con `<T>` conservada según la implementación actual.
     */
    <T> operator[](unsigned int index);

    /**
     * @brief Asigna o reemplaza datos mediante operador '=' (detalles en implementación).
     * @param record Referencia al registro a asignar.
     * @return true si la asignación fue exitosa.
     */
    bool operator=(T& record);

    /**
     * @brief Elimina o resta @p record del almacenamiento (según implementación).
     * @param record Referencia al registro a eliminar.
     * @return true si la operación fue exitosa.
     */
    bool operator-(T& record);

    /**
     * @brief Devuelve la cantidad de registros almacenados.
     * @return Número de registros.
     */
    int CountRecords();

    /**
     * @brief Realiza una copia de seguridad del archivo gestionado a @p backupFilePath.
     * @param backupFilePath Ruta del archivo de respaldo.
     * @return true si la copia de seguridad se realizó correctamente.
     */
    bool Backup(const string& backupFilePath);

    /**
     * @brief Restaura desde un archivo de respaldo ubicado en @p backupFilePath.
     * @param backupFilePath Ruta del archivo de respaldo a restaurar.
     * @return true si la restauración fue exitosa.
     */
    bool Restore(const string& backupFilePath);

    /**
     * @brief Exporta los registros a un archivo CSV en @p csvFilePath.
     * @param csvFilePath Ruta del archivo CSV de salida.
     * @return true si la exportación fue exitosa.
     */
    bool ExportToCSV(const string& csvFilePath);
};

#endif // FILESYSTEM_H
