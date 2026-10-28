# LabStruct — C++

Лабораторная работа №1: массив, односвязный и двусвязный списки, стек и очередь. В C++ также реализовано АВЛ-дерево (вариант 2).

Ветки: [C++](https://github.com/jhvdiso-collab/LabStruct/tree/c%2B%2B-version) · [Go](https://github.com/jhvdiso-collab/LabStruct/tree/go-version) · [обе версии](https://github.com/jhvdiso-collab/LabStruct/tree/main).

## Сборка и запуск

Нужны C++17 и CMake 3.20 или новее. Среда: Linux/macOS.

```bash
cmake -S . -B build -DBUILD_TESTING=OFF
cmake --build build -j2
./dbms --file file.data --query 'MPUSH arr 10'
./dbms --file file.data --query 'PRINT arr'
```

Каждый запуск выполняет одну команду. Данные сохраняются в файле между запусками; заранее создавать файл не нужно. Справка: `./dbms --help`.

## Проверка

Нужен Python 3.

```bash
bash scripts/check.sh
```

[Команды и примеры](COMMANDS.md) · [Отчёт](REPORT.md).
