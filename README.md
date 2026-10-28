# LabStruct — Go

Лабораторная работа №1: массив, односвязный и двусвязный списки, стек и очередь.

Ветки: [C++](https://github.com/jhvdiso-collab/LabStruct/tree/c%2B%2B-version) · [Go](https://github.com/jhvdiso-collab/LabStruct/tree/go-version) · [обе версии](https://github.com/jhvdiso-collab/LabStruct/tree/main).

## Сборка и запуск

Нужен Go 1.23 или новее.

```bash
go build -o build/labstruct .
./dbms --file file.data --query 'MPUSH arr 10'
./dbms --file file.data --query 'PRINT arr'
```

Каждый запуск выполняет одну команду. Данные сохраняются в файле между запусками; заранее создавать файл не нужно. Справка: `./dbms --help`.

## Проверка

Нужен Python 3.

```bash
bash scripts/check.sh
```

[Команды и примеры](COMMANDS.md).
