# Справочник команд проекта LabStruct

Команды ниже соответствуют C++-программе `data_structures_app`.

## Сборка и запуск

```bash
cd /home/ammar/LabStruct
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build -j2
./dbms --help
```

Общий вид запуска:

```bash
./dbms --file file.data --query 'КОМАНДА имя аргументы'
```

| Параметр | Назначение |
| --- | --- |
| `--file путь` | Файл для загрузки и сохранения структур. |
| `--query 'команда'` | Одна команда, заключённая в кавычки. |
| `--help` | Краткая справка; запускается отдельно от остальных параметров. |

Каждый запуск выполняет одну команду. Программа читает файл перед выполнением и сохраняет его при изменениях. Отсутствующий файл создаётся при первой успешной операции создания или добавления. Папка для файла должна существовать. Не создавай заранее пустой файл: программа ожидает собственный формат данных.

При желании вместо полного вызова можно использовать функцию `run` в терминале Bash:

```bash
source scripts/run.sh
run 'MPUSH arr 10'
```

После этого `run 'MPUSH arr 10'` равнозначно вызову
`./dbms --file file.data --query 'MPUSH arr 10'` из корня проекта.
Функция действует в текущем терминале и по умолчанию использует `file.data`
в корне проекта. Для другого файла задай `LABSTRUCT_FILE=/полный/путь/demo.data`.
Скрипт `dbms` запускает собранную программу из `build/data_structures_app`.

## Общие правила

- Команды пишутся заглавными буквами.
- `имя` — имя структуры: латинские буквы, цифры, `_` и `-`, без пробелов. Имена чувствительны к регистру.
- Имена уникальны внутри файла: нельзя использовать одно имя для массива и стека.
- `значение` — целое число от −2147483648 до 2147483647.
- `индекс` — позиция элемента, начиная с нуля.
- Для массива и списков допустимые индексы существующих элементов: от `0` до `длина - 1`.
- `MINSERT` допускает индекс от `0` до `длина` включительно.
- Команды списков `PUSHBEFORE`, `PUSHAFTER`, `DELBEFORE`, `DELAFTER` принимают индекс опорного элемента, а не его значение. Для удаления сосед должен существовать.
- `CREATE` создаёт пустую структуру и выводит `OK`. Повторное создание существующего имени — ошибка, данные не очищаются.
- `MPUSH`, `FPUSH`, `FPUSHFRONT`, `FPUSHBACK`, `LPUSH`, `LPUSHFRONT`, `LPUSHBACK`, `SPUSH`, `QPUSH`, `TINSERT` автоматически создают структуру, если её ещё нет. Остальные операции требуют существующую структуру.

## Общая команда вывода

| Команда | Действие и результат |
| --- | --- |
| `PRINT имя` | Вывод любой структуры в виде `[10 20 30]`; пустой — `[]`. Данные не меняются. |

Массив и списки выводятся от начала к концу, стек — от вершины, очередь — от головы. AVL-дерево выводится по возрастанию ключей, без отображения формы дерева.

## Массив — M

| Команда | Действие и результат |
| --- | --- |
| `MCREATE имя` | Создать пустой массив; `OK`. |
| `MPUSH имя значение` | Добавить в конец; вывести добавленное значение. |
| `MINSERT имя индекс значение` | Вставить на позицию, сдвинув последующие элементы вправо; вывести значение. |
| `MGET имя индекс` | Вывести элемент по индексу. |
| `MDEL имя индекс` | Удалить элемент, сдвинув последующие влево; вывести удалённое значение. |
| `MSET имя индекс значение` | Заменить элемент; вывести новое значение. |
| `MLEN имя` | Вывести количество элементов. |

```bash
./dbms --file file.data --query 'MCREATE arr'       # OK
./dbms --file file.data --query 'MPUSH arr 10'      # 10
./dbms --file file.data --query 'MPUSH arr 30'      # 30
./dbms --file file.data --query 'MINSERT arr 1 20'  # 20
./dbms --file file.data --query 'PRINT arr'         # [10 20 30]
./dbms --file file.data --query 'MGET arr 1'        # 20
./dbms --file file.data --query 'MSET arr 1 25'     # 25
./dbms --file file.data --query 'MDEL arr 0'        # 10
./dbms --file file.data --query 'MLEN arr'          # 2
./dbms --file file.data --query 'PRINT arr'         # [25 30]
```

## Односвязный список — F

| Команда | Действие и результат |
| --- | --- |
| `FCREATE имя` | Создать пустой список; `OK`. |
| `FPUSH имя значение` | Добавить в конец; вывести значение. |
| `FPUSHFRONT имя значение` | Добавить в голову; вывести значение. |
| `FPUSHBACK имя значение` | Добавить в хвост; аналог `FPUSH`. |
| `FPUSHBEFORE имя индекс значение` | Вставить перед элементом с указанным индексом; вывести значение. |
| `FPUSHAFTER имя индекс значение` | Вставить после элемента с указанным индексом; вывести значение. |
| `FGET имя индекс` | Вывести элемент по индексу. |
| `FFIND имя значение` | Вывести индекс первого совпадения или `-1`, если значения нет. |
| `FLEN имя` | Вывести количество элементов. |
| `FREVERSE имя` | Вывести список в обратном порядке, не изменяя его. |
| `FDEL имя индекс` | Удалить по индексу; вывести удалённое значение. |
| `FDELFRONT имя` | Удалить голову; вывести удалённое значение. |
| `FDELBACK имя` | Удалить хвост; вывести удалённое значение. |
| `FDELBEFORE имя индекс` | Удалить элемент перед указанным; вывести удалённое значение. |
| `FDELAFTER имя индекс` | Удалить элемент после указанного; вывести удалённое значение. |
| `FDELVAL имя значение` | Удалить первое совпадение; `TRUE`, если удалено, иначе `FALSE`. |

```bash
./dbms --file file.data --query 'FCREATE list1' # OK
./dbms --file file.data --query 'FPUSH list1 20' # 20
./dbms --file file.data --query 'FPUSHFRONT list1 10' # 10
./dbms --file file.data --query 'FPUSHBACK list1 40' # 40
./dbms --file file.data --query 'FPUSHBEFORE list1 2 30' # 30
./dbms --file file.data --query 'FPUSHAFTER list1 1 25' # 25
./dbms --file file.data --query 'PRINT list1' # [10 20 25 30 40]
./dbms --file file.data --query 'FGET list1 2' # 25
./dbms --file file.data --query 'FFIND list1 30' # 3
./dbms --file file.data --query 'FLEN list1' # 5
./dbms --file file.data --query 'FREVERSE list1' # [40 30 25 20 10]
./dbms --file file.data --query 'FDELBEFORE list1 2' # 20; остаётся [10 25 30 40]
./dbms --file file.data --query 'FDELAFTER list1 1' # 30; остаётся [10 25 40]
./dbms --file file.data --query 'FDELVAL list1 25' # TRUE; остаётся [10 40]
./dbms --file file.data --query 'FDEL list1 0' # 10
./dbms --file file.data --query 'FPUSHFRONT list1 5' # 5
./dbms --file file.data --query 'FDELFRONT list1' # 5
./dbms --file file.data --query 'FDELBACK list1' # 40
./dbms --file file.data --query 'PRINT list1' # []
```

## Двусвязный список — L

| Команда | Действие и результат |
| --- | --- |
| `LCREATE имя` | Создать пустой список; `OK`. |
| `LPUSH имя значение` | Добавить в конец; вывести значение. |
| `LPUSHFRONT имя значение` | Добавить в голову; вывести значение. |
| `LPUSHBACK имя значение` | Добавить в хвост; аналог `LPUSH`. |
| `LPUSHBEFORE имя индекс значение` | Вставить перед элементом с указанным индексом; вывести значение. |
| `LPUSHAFTER имя индекс значение` | Вставить после элемента с указанным индексом; вывести значение. |
| `LGET имя индекс` | Вывести элемент по индексу. |
| `LFIND имя значение` | Вывести индекс первого совпадения или `-1`. |
| `LLEN имя` | Вывести количество элементов. |
| `LREVERSE имя` | Вывести от хвоста к голове, не изменяя список. |
| `LDEL имя индекс` | Удалить по индексу; вывести удалённое значение. |
| `LDELFRONT имя` | Удалить голову; вывести удалённое значение. |
| `LDELBACK имя` | Удалить хвост; вывести удалённое значение. |
| `LDELBEFORE имя индекс` | Удалить элемент перед указанным; вывести удалённое значение. |
| `LDELAFTER имя индекс` | Удалить элемент после указанного; вывести удалённое значение. |
| `LDELVAL имя значение` | Удалить первое совпадение; `TRUE`, если удалено, иначе `FALSE`. |

```bash
./dbms --file file.data --query 'LCREATE list2' # OK
./dbms --file file.data --query 'LPUSH list2 20' # 20
./dbms --file file.data --query 'LPUSHFRONT list2 10' # 10
./dbms --file file.data --query 'LPUSHBACK list2 40' # 40
./dbms --file file.data --query 'LPUSHBEFORE list2 2 30' # 30
./dbms --file file.data --query 'LPUSHAFTER list2 1 25' # 25
./dbms --file file.data --query 'PRINT list2' # [10 20 25 30 40]
./dbms --file file.data --query 'LGET list2 2' # 25
./dbms --file file.data --query 'LFIND list2 30' # 3
./dbms --file file.data --query 'LLEN list2' # 5
./dbms --file file.data --query 'LREVERSE list2' # [40 30 25 20 10]
./dbms --file file.data --query 'LDELBEFORE list2 2' # 20; остаётся [10 25 30 40]
./dbms --file file.data --query 'LDELAFTER list2 1' # 30; остаётся [10 25 40]
./dbms --file file.data --query 'LDELVAL list2 25' # TRUE; остаётся [10 40]
./dbms --file file.data --query 'LDEL list2 0' # 10
./dbms --file file.data --query 'LPUSHFRONT list2 5' # 5
./dbms --file file.data --query 'LDELFRONT list2' # 5
./dbms --file file.data --query 'LDELBACK list2' # 40
./dbms --file file.data --query 'PRINT list2' # []
```

## Стек — S

Принцип LIFO: последним добавлен — первым извлечён.

| Команда | Действие и результат |
| --- | --- |
| `SCREATE имя` | Создать пустой стек; `OK`. |
| `SPUSH имя значение` | Добавить на вершину; вывести добавленное значение. |
| `SGET имя` | Вывести значение на вершине без удаления. |
| `SPOP имя` | Удалить вершину и вывести её значение. |

```bash
./dbms --file file.data --query 'SCREATE stack1' # OK
./dbms --file file.data --query 'SPUSH stack1 10'
./dbms --file file.data --query 'SPUSH stack1 20'
./dbms --file file.data --query 'PRINT stack1'  # [20 10]
./dbms --file file.data --query 'SGET stack1'   # 20
./dbms --file file.data --query 'SPOP stack1'   # 20
./dbms --file file.data --query 'PRINT stack1'  # [10]
```

## Очередь — Q

Принцип FIFO: первым добавлен — первым извлечён.

| Команда | Действие и результат |
| --- | --- |
| `QCREATE имя` | Создать пустую очередь; `OK`. |
| `QPUSH имя значение` | Добавить в хвост; вывести добавленное значение. |
| `QGET имя` | Вывести значение в голове без удаления. |
| `QPOP имя` | Удалить голову и вывести её значение. |

```bash
./dbms --file file.data --query 'QCREATE queue1' # OK
./dbms --file file.data --query 'QPUSH queue1 10'
./dbms --file file.data --query 'QPUSH queue1 20'
./dbms --file file.data --query 'PRINT queue1'  # [10 20]
./dbms --file file.data --query 'QGET queue1'   # 10
./dbms --file file.data --query 'QPOP queue1'   # 10
./dbms --file file.data --query 'PRINT queue1'  # [20]
```

## AVL-дерево — T

В интерфейсе используется AVL-дерево (вариант 2 ТЗ). Отдельных команд для обычного BST нет. Ключи AVL уникальны; после вставки и удаления сохраняется балансировка.

| Команда | Действие и результат |
| --- | --- |
| `TCREATE имя` | Создать пустое дерево; `OK`. |
| `TINSERT имя значение` | Добавить ключ; `TRUE`, если добавлен, `FALSE`, если уже есть. |
| `TGET имя значение` | Проверить наличие ключа; `TRUE` или `FALSE`. |
| `ISMEMBER имя значение` | Аналог `TGET`. |
| `TSHOW имя` | Показать форму АВЛ, высоты `h` и баланс `b` каждого узла. |
| `TDEL имя значение` | Удалить ключ; `TRUE`, если удалён, `FALSE`, если отсутствует. |

```bash
./dbms --file file.data --query 'TCREATE tree1' # OK
./dbms --file file.data --query 'TINSERT tree1 30'  # TRUE
./dbms --file file.data --query 'TINSERT tree1 20'  # TRUE
./dbms --file file.data --query 'TINSERT tree1 10'  # TRUE
./dbms --file file.data --query 'PRINT tree1'       # [10 20 30]
./dbms --file file.data --query 'TSHOW tree1'       # Схема дерева после загрузки из файла
./dbms --file file.data --query 'TINSERT tree1 20'  # FALSE
./dbms --file file.data --query 'TGET tree1 20'     # TRUE
./dbms --file file.data --query 'ISMEMBER tree1 99' # FALSE
./dbms --file file.data --query 'TDEL tree1 20'     # TRUE
./dbms --file file.data --query 'PRINT tree1'       # [10 30]
```

В `TSHOW` корень отмечен `ROOT`, потомки — `L` и `R`, вложенность показана
отступами. Баланс `b` равен высоте правого поддерева минус высота левого.
Высота листа равна 1. Пустое дерево выводится как `[]`.
Команда не изменяет данные. Файл хранит ключи, поэтому схема относится к
восстановленному дереву текущего запуска, а не к состоянию прошлого процесса.

## Ошибки и сохранение данных

При ошибке программа выводит `Error: ...` и завершается с кодом `1`; при успешном выполнении код завершения — `0`.

| Ситуация | Пример сообщения |
| --- | --- |
| Неверный индекс массива | `Array index` |
| Неверный индекс списка или отсутствующий сосед | `List index` |
| Чтение или удаление из пустого стека | `Empty stack` |
| Чтение или удаление из пустой очереди | `Empty queue` |
| Повторный `CREATE` | `Container already exists` |
| Команда не соответствует типу структуры | `Container type mismatch` |
| Ошибка в числе аргументов | `Wrong argument count` |

Пример после выполнения раздела про массив:

```bash
./dbms --file file.data --query 'MGET arr 99'  # Error: Array index
./dbms --file file.data --query 'PRINT arr'    # [25 30], массив не изменился
cat file.data     # показать сохранённые структуры
```

Каждая команда запускается отдельным процессом: сохранение значений между вызовами демонстрирует работу с файлом. Команды чтения файл не перезаписывают.

Примеры разделов рассчитаны на последовательное выполнение с новым файлом `file.data`. Для повторной демонстрации замени `--file file.data` во всех вызовах на другое, ещё не занятое имя, например `--file demo2.data`. Пример с `run` из введения запускай отдельно: он тоже изменяет данные.

## Проверка проекта

```bash
ctest --test-dir build --output-on-failure
```

Запускаются два набора проверок: операции структур (в том числе высота и баланс AVL после изменений) и командный интерфейс с сохранением и загрузкой файлов.
