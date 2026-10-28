# Подключение из корня проекта: source scripts/run.sh
LABSTRUCT_ROOT=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)

run() {
    if [[ $# -ne 1 ]]; then
        echo "Использование: run 'КОМАНДА имя аргументы'" >&2
        return 1
    fi
    "$LABSTRUCT_ROOT/dbms" --file "${LABSTRUCT_FILE:-$LABSTRUCT_ROOT/file.data}" --query "$1"
}
