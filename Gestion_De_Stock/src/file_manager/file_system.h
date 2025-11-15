#ifndef FILESYSTEM_H
#define FILESYSTEM_H

using namespace std;

template <typename T>
class FileSystem {
private:
    const string filePath;

    static unsigned int counter;

    bool IndexOf(T& record, unsigned int& index);
    bool CreateRecord(T& record);
    <T> ReadRecord(unsigned int index);
    bool UpdateRecord(unsigned int index, T& record);
    bool DeleteRecord(unsigned int index);

public:
    FileSystem(const string& _filePath);
    ~FileSystem();

    <T> LastRegistry();
    <T> ListAll();

    bool operator==(T& record);
    bool operator+(T& record);
    <T> operator[](unsigned int index);
    bool operator=(T& record);
    bool operator-(T& record);

    int CountRecords();
    bool Backup(const string& backupFilePath);
    bool Restore(const string& backupFilePath);
    bool ExportToCSV(const string& csvFilePath);
};

#endif // FILESYSTEM_H
