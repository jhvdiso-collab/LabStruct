# Команды LabStruct

Запуск C++: `./dbms --file demo.data --query 'КОМАНДА имя аргументы'`.
Go: `go run . --file demo.data --query 'КОМАНДА имя аргументы'` из каталога Go (в main это go/).
Все элементы, кроме ключей AVL, являются строками без пробелов. Индексы начинаются с 0. Дерево реализовано на C++.

| Контейнер | Команды (после команды указывается имя) |
|---|---|
| M | MCREATE, MPUSH значение, MINSERT индекс значение, MGET индекс, MDEL индекс, MSET индекс значение, MLEN |
| F / L | CREATE, PUSH значение, PUSHFRONT значение, PUSHBACK значение, PUSHBEFORE опора значение, PUSHAFTER опора значение, DEL индекс, DELFRONT, DELBACK, DELBEFORE опора, DELAFTER опора, DELVAL значение, FIND значение, GET индекс, GETFRONT, GETBACK, LEN, REVERSE (с префиксом F или L) |
| S | SCREATE, SPUSH значение, SPOP, SGET |
| Q | QCREATE, QPUSH значение, QPOP, QGET |
| T (C++) | TCREATE, TINSERT число, TGET число, TDEL число, ISMEMBER число, TSHOW |

PRINT имя выводит структуру без изменения. REVERSE выводит список в обратном порядке.
Опора — **значение**, а не индекс; при повторениях используется первое совпадение.
При отсутствии опоры или соседа операция завершается ошибкой, файл не изменяется.
PUSH, PUSHFRONT, PUSHBACK и TINSERT могут создавать контейнер автоматически.
DELVAL удаляет первое совпадение и возвращает TRUE/FALSE; FIND возвращает индекс либо -1.

Пример (повторить для L):
```
FPUSH list beta
FPUSHFRONT list alpha
FPUSHBACK list delta
FPUSHBEFORE list delta gamma
FPUSHAFTER list alpha extra
PRINT list
FDELBEFORE list beta
FDELAFTER list beta
FGETFRONT list
FGETBACK list
FREVERSE list
FDELVAL list beta
FDELFRONT list
FDELBACK list
PRINT list
```
