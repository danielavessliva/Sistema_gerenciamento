let itens = [];
let despesas = [];

function calcularGastos() {
    // Variável para armazenar o total
    let total = 0;

    // Obtendo os valores dos gastos fixos
    const agua = parseFloat(document.getElementById('agua').value);
    const energia = parseFloat(document.getElementById('energia').value);
    const telefone = parseFloat(document.getElementById('telefone').value);
    const internet = parseFloat(document.getElementById('internet').value);
    const aluguel = parseFloat(document.getElementById('aluguel').value);

    // Somando os gastos fixos
    total += agua + energia + telefone + internet + aluguel;

    // Obtendo os valores dos custos adicionais
    const custosAdicionais = document.querySelectorAll('#custos-adicionais input[type="number"]');
    for (const custo of custosAdicionais) {
        total += parseFloat(custo.value);
    }

    // Exibindo o resultado
    document.getElementById('resultado').textContent = `Total: R$ ${total.toFixed(2)}`;
}


function adicionarCusto() {
    // Create input and label elements
    const novoCusto = document.createElement('input');
    novoCusto.type = 'number';
    novoCusto.step = '0.01';
    const novoRótulo = document.createElement('label');
  
    // Prompt for title and set label text
    const titulo = prompt("Digite o título do custo:");
    if (titulo) {
      novoRótulo.textContent = titulo + ": ";
    } else {
      novoRótulo.textContent = "Custo Adicional: "; // Default if no title entered
    }
  
    // Create container and append elements
    const containerCusto = document.createElement('div');
    containerCusto.appendChild(novoRótulo);
    containerCusto.appendChild(novoCusto);
  
    // Append container to #custos-adicionais
    const custosAdicionais = document.getElementById('custos-adicionais');
    custosAdicionais.appendChild(containerCusto);
  }
  

function listarItens() {
    const listaItens = document.getElementById('lista-itens-ul');
    listaItens.innerHTML = ''; // Limpar lista antes de adicionar

    itens.forEach(item => {
        const li = document.createElement('li');
        li.textContent = `${item.nome}: R$ ${item.valor.toFixed(2)}`;
        listaItens.appendChild(li);
    });
}

function excluirItem(indice) {
    itens.splice(indice, 1);
    atualizarListaItens();
}

function atualizarListaItens() {
    listarItens();
    atualizarRelatorio();
}

function atualizarRelatorio() {
    const totalItens = itens.reduce((soma, item) => soma + item.valor, 0);
    const totalDespesas = despesas.reduce((soma, despesa) => soma + despesa.valor, 0);
    const saldo = totalItens - totalDespesas;

    document.getElementById('total-itens').textContent = `Total de Itens: R$ ${totalItens.toFixed(2)}`;
    document.getElementById('total-despesas').textContent = `Total de Despesas: R$ ${totalDespesas.toFixed(2)}`;
    document.getElementById('saldo').textContent = `Saldo: R$ ${saldo.toFixed(2)}`;
}

function gerarRelatorio() {
    const relatorio = gerarRelatorioTexto(itens, despesas);
    alert(relatorio);
}

function gerarRelatorioTexto(listaItens, listaDespesas) {
    let texto = '';

    texto += '## Relatório de Gastos\n\n';

    if (listaItens.length > 0) {
        texto += '### Itens:\n';
        listaItens.forEach(item => {
            texto += ` - ${item.nome}: R$ ${item.valor.toFixed(2)}\n`;
        });
    } else {
        texto += ' - Sem itens cadastrados.\n';
    }

    if (listaDespesas.length > 0) {
        texto += '\n### Despesas:\n';
        listaDespesas.forEach(despesa => {
            texto += ` - ${despesa.nome}: R$ ${despesa.valor.toFixed(2)}\n`;
        });
    } else {
        texto += ' - Sem despesas cadastradas.\n';
    }

    texto += '\n## Saldo Final:\n';
    const totalItens = listaItens.reduce((soma, item) => soma + item.valor, 0);
    const totalDespesas = listaDespesas.reduce((soma, despesa) => soma + despesa.valor, 0);
    const saldo = totalItens - totalDespesas;
    texto += ` - R$ ${saldo.toFixed(2)}\n`;

    return texto;
}

function limparForm(seletorForm) {
    const form = document.querySelector(seletorForm);
    form.querySelectorAll('input[type="text"], input[type="number"]').forEach(input => input.value = '');
}
