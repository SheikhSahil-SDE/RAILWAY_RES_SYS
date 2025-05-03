document.getElementById('input-elements').addEventListener('click', function() {
    const rows = parseInt(document.getElementById('rows').value);
    const columns = parseInt(document.getElementById('columns').value);

    if (rows > 0 && columns > 0) {
        const matrixInputs = document.getElementById('matrix-inputs');
        matrixInputs.innerHTML = '';

        for (let i = 0; i < rows; i++) {
            const rowDiv = document.createElement('div');
            for (let j = 0; j < columns; j++) {
                const input = document.createElement('input');
                input.type = 'number';
                input.className = 'matrix-cell';
                input.name = `cell-${i}-${j}`;
                input.required = true;
                rowDiv.appendChild(input);
            }
            matrixInputs.appendChild(rowDiv);
        }

        document.getElementById('matrix-elements-form').style.display = 'block';
    } else {
        alert('Please enter valid dimensions for the matrix.');
    }
});

document.getElementById('compute-transpose').addEventListener('click', function() {
    const rows = parseInt(document.getElementById('rows').value);
    const columns = parseInt(document.getElementById('columns').value);
    const matrix = [];

    for (let i = 0; i < rows; i++) {
        const row = [];
        for (let j = 0; j < columns; j++) {
            const cellValue = document.querySelector(`input[name='cell-${i}-${j}']`).value;
            row.push(parseInt(cellValue));
        }
        matrix.push(row);
    }

    const transpose = [];
    for (let i = 0; i < columns; i++) {
        const row = [];
        for (let j = 0; j < rows; j++) {
            row.push(matrix[j][i]);
        }
        transpose.push(row);
    }

    const transposeOutput = document.getElementById('transpose-output');
    transposeOutput.innerHTML = '';
    transpose.forEach(row => {
        const rowDiv = document.createElement('div');
        row.forEach(cell => {
            const cellDiv = document.createElement('span');
            cellDiv.textContent = cell;
            cellDiv.className = 'transpose-cell';
            rowDiv.appendChild(cellDiv);
        });
        transposeOutput.appendChild(rowDiv);
    });

    document.getElementById('result').style.display = 'block';
});