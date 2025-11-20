#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>

using namespace std;

template <typename T>
class FileSystem {
private:
    /** @brief Ruta del archivo que gestiona este FileSystem. */
    const string filePath;

public:
    /**
     * @brief Construye un FileSystem asociado a la ruta @p _filePath.
     * @param _filePath Ruta del archivo a gestionar.
     */
    FileSystem(const string& _filePath);

    /** @brief Destructor: realiza limpieza necesaria al destruir la instancia. */
    ~FileSystem();

    /**
     * @brief Devuelve la cantidad de registros almacenados.
     * @return Número de registros.
     */
    unsigned int Count();

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
    bool New(T& record);

    /**
     * @brief Lee y devuelve el registro en la posición @p index.
     * @param index Índice del registro a leer.
     * @return Copia del registro leído.
     * @note La firma actual utiliza un marcador ` T` que puede no ser sintácticamente
     *       estándar en C++; se conserva aquí según la implementación existente.
     */
    T* At(unsigned int index);

    /**
     * @brief Actualiza el registro en la posición @p index con los datos de @p record.
     * @param index Índice del registro a actualizar.
     * @param record Referencia con los nuevos datos.
     * @return true si la actualización fue exitosa.
     */
    bool Update(unsigned int index, T& record);

    /**
     * @brief Elimina el registro en la posición @p index.
     * @param index Índice del registro a eliminar.
     * @return true si la eliminación fue exitosa.
     */
    bool Delete(unsigned int index);

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
};

template <typename T>
FileSystem<T>::FileSystem(const string& _filePath) : filePath(_filePath) {

}

template <typename T>
FileSystem<T>::~FileSystem() {

}

template <typename T>
unsigned int FileSystem<T>::Count() {
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return 0;
    }
    unsigned int count = 0;
    T tempRecord;
    while(fread(&tempRecord, sizeof(T), 1, file)) {
        count++;
    }
    fclose(file);
    return count;
}

template <typename T>
bool FileSystem<T>::IndexOf(T& record, unsigned int& index) {
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return false;
    }
    bool found = false;
    T tempRecord;
    unsigned int current = 0;
    while(fread(&tempRecord, sizeof(T), 1, file)) {
        if(tempRecord == record) {
            found = true;
            index = current;
            break;
        }
        current++;
    }
    fclose(file);
    return found;
}

template <typename T>
bool FileSystem<T>::New(T& record) {
    FILE* file = fopen(this->filePath.c_str(), "ab");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return false;
    }
    bool result = fwrite(&record, sizeof(T), 1, file);
    fclose(file);
    return result;
}

template <typename T>
T* FileSystem<T>::At(unsigned int index) {
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return nullptr;
    }
    fseek(file, sizeof(T) * index, SEEK_SET);
    T* record = new T();
    bool result = fread(record, sizeof(T), 1, file);
    fclose(file);
    if(!result) {
        delete record;
        cerr << "Error: No se pudo reservar memoria para el registro" << endl;
        return nullptr;
    }
    return record;
}

template <typename T>
bool FileSystem<T>::Update(unsigned int index, T& record) {
    FILE* file = fopen(this->filePath.c_str(), "r+b");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return false;
    }
    fseek(file, sizeof(T) * index, SEEK_SET);
    bool result = fwrite(&record, sizeof(T), 1, file);
    fclose(file);
    return result;
}

template <typename T>
bool FileSystem<T>::Delete(unsigned int index) {
    if(index >= this->Count()) {
        cerr << "Error: Posicion a eliminar incorrecta o no existe" << endl;
        return false;
    }
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return false;
    }
    FILE* tempFile = fopen("temp.dat", "wb");
    if(tempFile == nullptr) {
        cerr << "Error: No se pudo crear el archivo temporal" << endl;
        fclose(file);
        return false;
    }
    T tempRecord;
    unsigned int currentIndex = 0;
    while(fread(&tempRecord, sizeof(T), 1, file)) {
        if(currentIndex != index) {
            fwrite(&tempRecord, sizeof(T), 1, tempFile);
        }
        currentIndex++;
    }
    fclose(file);
    fclose(tempFile);
    remove(this->filePath.c_str());
    rename("temp.dat", this->filePath.c_str());
    return true;
}

template <typename T>
bool FileSystem<T>::Backup(const string& backupFilePath) {
    FILE* sourceFile = fopen(this->filePath.c_str(), "rb");
    if(sourceFile == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        return false;
    }
    FILE* destFile = fopen(backupFilePath.c_str(), "wb");
    if(destFile == nullptr) {
        cerr << "Error: No se pudo crear el archivo de respaldo " << backupFilePath << endl;
        fclose(sourceFile);
        return false;
    }
    T tempRecord;
    while(fread(&tempRecord, sizeof(T), 1, sourceFile)) {
        fwrite(&tempRecord, sizeof(T), 1, destFile);
    }
    fclose(sourceFile);
    fclose(destFile);
    return true;
}

template <typename T>
bool FileSystem<T>::Restore(const string& backupFilePath) {
    FILE* backupFile = fopen(backupFilePath.c_str(), "rb");
    if(backupFile == nullptr) {
        cerr << "Error: No se pudo abrir el archivo de respaldo " << backupFilePath << endl;
        return false;
    }
    FILE* destFile = fopen(this->filePath.c_str(), "wb");
    if(destFile == nullptr) {
        cerr << "Error: No se pudo abrir el archivo " << this->filePath << endl;
        fclose(backupFile);
        return false;
    }
    T tempRecord;
    while(fread(&tempRecord, sizeof(T), 1, backupFile)) {
        fwrite(&tempRecord, sizeof(T), 1, destFile);
    }
    fclose(backupFile);
    fclose(destFile);
    return true;
}

#endif // FILESYSTEM_H
