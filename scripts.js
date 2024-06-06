function calcularGastos() {
    let agua = parseFloat(document.getElementById('agua').value) || 0;
    let energia = parseFloat(document.getElementById('energia').value) || 0;
    let telefone = parseFloat(document.getElementById('telefone').value) || 0;
    let internet = parseFloat(document.getElementById('internet').value) || 0;
    let aluguel = parseFloat(document.getElementById('aluguel').value) || 0;
    let totalGastosFixos = agua + energia + telefone + internet + aluguel;

    // Coletando custos adicionais
    let custosAdicionais = document.getElementsByClassName('custo-adicional');
    for (let i = 0; i < custosAdicionais.length; i++) {
        totalGastosFixos += parseFloat(custosAdicionais[i].value) || 0;
    }

    document.getElementById('resultado').innerText = `Total de gastos fixos R$: ${totalGastosFixos.toFixed(2)}`;
}

function adicionarCusto() {
    let div = document.createElement('div');
    let inputNome = document.createElement('input');
    let inputCusto = document.createElement('input');
    let br = document.createElement('br');

    inputNome.setAttribute('type', 'text');
    inputNome.setAttribute('placeholder', 'Nome do custo adicional');
    inputCusto.setAttribute('type', 'number');
    inputCusto.setAttribute('placeholder', 'Valor do custo adicional');
    inputCusto.className = 'custo-adicional';

    div.appendChild(inputNome);
    div.appendChild(inputCusto);
    div.appendChild(br);

    document.getElementById('custos-adicionais').appendChild(div);
}
