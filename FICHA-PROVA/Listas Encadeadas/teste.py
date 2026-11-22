import json
import os
from datetime import datetime

ARQUIVO = "tarefas.json"

def carregar_tarefas():
    if not os.path.exists(ARQUIVO):
        return []
    with open(ARQUIVO, "r", encoding="utf-8") as f:
        return json.load(f)

def salvar_tarefas(tarefas):
    with open(ARQUIVO, "w", encoding="utf-8") as f:
        json.dump(tarefas, f, indent=4, ensure_ascii=False)

def adicionar_tarefa(tarefas, descricao):
    tarefa = {
        "id": len(tarefas) + 1,
        "descricao": descricao,
        "concluida": False,
        "criada_em": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }
    tarefas.append(tarefa)
    salvar_tarefas(tarefas)
    print("Tarefa adicionada.")

def listar_tarefas(tarefas):
    if not tarefas:
        print("Nenhuma tarefa encontrada.")
        return
    for t in tarefas:
        status = "✔" if t["concluida"] else "✘"
        print(f'{t["id"]}. [{status}] {t["descricao"]} ({t["criada_em"]})')

def concluir_tarefa(tarefas, tarefa_id):
    for t in tarefas:
        if t["id"] == tarefa_id:
            t["concluida"] = True
            salvar_tarefas(tarefas)
            print("Tarefa concluída.")
            return
    print("Tarefa não encontrada.")

def remover_tarefa(tarefas, tarefa_id):
    nova_lista = [t for t in tarefas if t["id"] != tarefa_id]
    if len(nova_lista) == len(tarefas):
        print("Tarefa não encontrada.")
        return
    salvar_tarefas(nova_lista)
    print("Tarefa removida.")

def menu():
    print("\n--- GERENCIADOR DE TAREFAS ---")
    print("1. Listar tarefas")
    print("2. Adicionar tarefa")
    print("3. Concluir tarefa")
    print("4. Remover tarefa")
    print("5. Sair")

def main():
    tarefas = carregar_tarefas()

    while True:
        menu()
        opcao = input("Escolha uma opção: ")

        if opcao == "1":
            listar_tarefas(tarefas)

        elif opcao == "2":
            descricao = input("Descrição da tarefa: ")
            adicionar_tarefa(tarefas, descricao)
            tarefas = carregar_tarefas()

        elif opcao == "3":
            try:
                tarefa_id = int(input("ID da tarefa: "))
                concluir_tarefa(tarefas, tarefa_id)
                tarefas = carregar_tarefas()
            except ValueError:
                print("ID inválido.")

        elif opcao == "4":
            try:
                tarefa_id = int(input("ID da tarefa: "))
                remover_tarefa(tarefas, tarefa_id)
                tarefas = carregar_tarefas()
            except ValueError:
                print("ID inválido.")

        elif opcao == "5":
            print("Saindo...")
            break

        else:
            print("Opção inválida.")

def inicializar_arquivo():
    if not os.path.exists(ARQUIVO):
        salvar_tarefas([])

def limpar_tarefas_concluidas(tarefas):
    tarefas = [t for t in tarefas if not t["concluida"]]
    salvar_tarefas(tarefas)
    print("Tarefas concluídas removidas.")
    return tarefas

def buscar_tarefa(tarefas, termo):
    resultados = [t for t in tarefas if termo.lower() in t["descricao"].lower()]
    if not resultados:
        print("Nenhuma tarefa encontrada com esse termo.")
        return
    for t in resultados:
        status = "✔" if t["concluida"] else "✘"
        print(f'{t["id"]}. [{status}] {t["descricao"]}')

def estatisticas(tarefas):
    total = len(tarefas)
    concluidas = len([t for t in tarefas if t["concluida"]])
    pendentes = total - concluidas
    print(f"Total: {total}")
    print(f"Concluídas: {concluidas}")
    print(f"Pendentes: {pendentes}")

def menu_extra():
    print("\n--- EXTRAS ---")
    print("6. Limpar tarefas concluídas")
    print("7. Buscar tarefa")
    print("8. Estatísticas")

def main_completo():
    inicializar_arquivo()
    tarefas = carregar_tarefas()

    while True:
        menu()
        menu_extra()
        opcao = input("Escolha uma opção: ")

        if opcao in ["1","2","3","4","5"]:
            if opcao == "1":
                listar_tarefas(tarefas)

            elif opcao == "2":
                descricao = input("Descrição: ")
                adicionar_tarefa(tarefas, descricao)
                tarefas = carregar_tarefas()

            elif opcao == "3":
                try:
                    tarefa_id = int(input("ID: "))
                    concluir_tarefa(tarefas, tarefa_id)
                    tarefas = carregar_tarefas()
                except:
                    print("Erro.")

            elif opcao == "4":
                try:
                    tarefa_id = int(input("ID: "))
                    remover_tarefa(tarefas, tarefa_id)
                    tarefas = carregar_tarefas()
                except:
                    print("Erro.")

            elif opcao == "5":
                break

        elif opcao == "6":
            tarefas = limpar_tarefas_concluidas(tarefas)

        elif opcao == "7":
            termo = input("Buscar: ")
            buscar_tarefa(tarefas, termo)

        elif opcao == "8":
            estatisticas(tarefas)

        else:
            print("Inválido.")

if __name__ == "__main__":
    main_completo()