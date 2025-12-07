#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <iostream>

#include "../controller/modals.h"

using namespace std;

template <typename T>
class FileSystem {
private:
    /** @brief Ruta del archivo que gestiona este FileSystem. */
    const string filePath;

protected:
    /**
     * @brief Verifica si un registro existe en el almacenamiento.
     * @param record Referencia al registro a verificar.
     * @return true si el registro existe; false en caso contrario.
     */
    bool Exist(T& record);

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
     * @brief Sobrecarga del operador de indexación para acceder a registros.
     * @param index Índice del registro a acceder.
     * @return Puntero al registro en la posición @p index.
     */
    T* operator[](unsigned int index);

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
FileSystem<T>::~FileSystem() { }

template <typename T>
bool FileSystem<T>::Exist(T& record) {
    const unsigned int cout_ = this->Count();
    unsigned int i = 0;
    while(i < cout_) {
        T* aux = this->At(i);
        if(*aux == record) {
            return true;
        }
        i++;
    }
    return false;
}

template <typename T>
unsigned int FileSystem<T>::Count() {
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        Error mi_error("Conteo de Registros", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
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
        Error mi_error("Busqueda de Registro", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
        return false;
    }
    bool found = false;
    T tempRecord;
    unsigned int current = 0;
    while(fread(&tempRecord, sizeof(T), 1, file)) {
        bool result = tempRecord == record;
        if(result) {
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
T* FileSystem<T>::operator[](unsigned int index) {
    return At(index);
}

template <typename T>
bool FileSystem<T>::New(T& record) {
    FILE* file = fopen(this->filePath.c_str(), "ab");
    if(file == nullptr) {
        Error mi_error("Creacion de Registro", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
        return false;
    }
    if(Exist(record)) {
        Warning mi_warning("Creacion de Registro", "El registro ya existe en el archivo " + this->filePath + ".");
        mi_warning.Show();
        fclose(file);
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
        Error mi_error("Lectura de Registro", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
        return nullptr;
    }
    T* record = new T();
    fseek(file, sizeof(T) * index, SEEK_SET);
    bool result = fread(record, sizeof(T), 1, file);
    fclose(file);
    if(!result) {
        delete record;
        Warning mi_warning("Lectura de Registro", "No se pudo leer el registro en la posicion " + to_string(index) + " del archivo " + this->filePath + ".");
        mi_warning.Show();
        return nullptr;
    }
    return record;
}

template <typename T>
bool FileSystem<T>::Update(unsigned int index, T& record) {
    FILE* file = fopen(this->filePath.c_str(), "r+b");
    if(file == nullptr) {
        Error mi_error("Actualizacion de Registro", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
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
        Warning mi_warning("Eliminacion de Registro", "No se puede eliminar el registro en la posicion " + to_string(index) + " porque es incorrecta o no existe.");
        mi_warning.Show();
        return false;
    }
    FILE* file = fopen(this->filePath.c_str(), "rb");
    if(file == nullptr) {
        Error mi_error("Eliminacion de Registro", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
        return false;
    }
    FILE* tempFile = fopen("temp.dat", "wb");
    if(tempFile == nullptr) {
        Error mi_error("Eliminacion de Registro", "No se pudo crear el archivo temporal para la eliminacion.");
        mi_error.Show();
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
        Error mi_error("Copia de Seguridad", "No se pudo abrir el archivo " + this->filePath + ".");
        mi_error.Show();
        return false;
    }
    FILE* destFile = fopen(backupFilePath.c_str(), "wb");
    if(destFile == nullptr) {
        Error mi_error("Copia de Seguridad", "No se pudo crear el archivo de respaldo " + backupFilePath + ".");
        mi_error.Show();
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
        Error mi_error("Restauracion desde Respaldo", "No se pudo abrir el archivo de respaldo " + backupFilePath + ".");
        mi_error.Show();
        return false;
    }
    FILE* destFile = fopen(this->filePath.c_str(), "wb");
    if(destFile == nullptr) {
        Error mi_error("Restauracion desde Respaldo", "No se pudo abrir el archivo " + this->filePath + " para restauracion.");
        mi_error.Show();
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
