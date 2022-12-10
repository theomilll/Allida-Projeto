# Allida-Projeto
## Equipe:
* [Henrique Leal](https://www.linkedin.com/in/henrique-leal-b24172234/)
* [Théo Moura](https://www.linkedin.com/in/theo-moura-011662232/)
* [Victor Montenegro](https://www.linkedin.com/in/victor-montenegro-833599234/)
* [Pedro Lino](https://www.linkedin.com/in/pedro-lino-4ab6621a1/)
* [Bernardo Nunes]()
* [Gabriella Tereza](https://www.linkedin.com/in/gabriella-bortolini-0508ba237/)
* [Marina Simões]()
* [Elissa Vangasse]()
* [Leonardo Cavalcanti]()
# Utilização

Instalar o projeto usando o venv é recomendado, porém é possível instalar sem usá-lo também.

Ative o virtualenv no projeto:

    $ virtualenv project-env
    $ source project-env/bin/activate

Caso não tenha o django instalado ainda execute:

    $ pip3 install django
    
Screencast da utilização do produto: https://drive.google.com/file/d/1HbWFwMYaQ5X6poGqCngDBcQl2AdSt6zr/view

# Começando

Primeiramente clone esse repositório do Github e entre em seu diretório:

    $ git clone https://github.com/henriquelealm/Allida-Projeto.git
    $ cd Allida-Projeto
    
Instale os requirements:

    $ pip install requirements.txt
    
    
Aplique as migrações do banco de dados:

    $ python manage.py migrate
    

Agora, basta apenas rodar o servidor localmente:

    $ python manage.py runserver

Dentro dessa pasta, haverá um arquivo databaseC.exe, que ao ser executado pelo próprio windows, irá enviar informações de quedas para o Django.
