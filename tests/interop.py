"""Verify C++/Go persistence compatibility, including preservation of AVL records."""
import pathlib
import subprocess
import sys
import tempfile

cpp, go = sys.argv[1:]
with tempfile.TemporaryDirectory() as directory:
    path = str(pathlib.Path(directory) / 'shared.data')
    def query(exe, command, expected):
        p = subprocess.run([exe, '--file', path, '--query', command], check=True,
                           capture_output=True, text=True, timeout=10)
        assert p.stdout.strip() == expected, (command, p.stdout, expected)
    for kind in 'MFLSQ':
        query(cpp, f'{kind}PUSH {kind.lower()} 1', '1')
        query(go, f'{kind}PUSH {kind.lower()} 2', '2')
        query(cpp, f'PRINT {kind.lower()}', '[2 1]' if kind == 'S' else '[1 2]')
    for value in [30, 10, 20, 40, 50, 25]:
        query(cpp, f'TINSERT t {value}', 'TRUE')
    query(go, 'MPUSH m 3', '3')
    query(cpp, 'PRINT t', '[10 20 25 30 40 50]')
    query(cpp, 'TDEL t 30', 'TRUE')
    query(go, 'PRINT m', '[1 2 3]')
print('PASS: shared format for all linear structures; Go preserves C++ AVL data')
