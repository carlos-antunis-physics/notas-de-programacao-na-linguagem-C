#   Fundamentos da linguagem C

A `linguagem C` consiste numa linguagem de programação de alto nível (mesmo que, por meio desta, possuamos acesso direto à memória da máquina). Esta segue o paradigma imperativo, onde o programador instri à máquina quais processos esta deve executar num arquivo denominado **código-fonte**.

>   [**Exemplo de código-fonte em C**](./1.ola.c)
>
>   Um exemplo elementar de código-fonte implementado na `linguagem C` é o que se segue:
>
> ```c
>//  inclua o cabeçalho de procedimentos padrão de leitura e escrita
>#include <stdio.h>
>
>int main(void) {                    // rotina principal (main) do programa
>    // escreva 'Olá mundo' seguido de uma nova linha ('\n') na saída
>    // padrão do computador
>    printf("Olá mundo\n");
>    return 0;                       // retorne erro 0 (sucesso)
>}
>```
>
>   o resultado deste programa é a inserção de *olá mundo* na saída padrão, que no nosso caso será o terminal.

para executar um código-fonte escrito na `linguagem C` precisamos compilá-lo num programa executável, utilizando um software denominado compilador (a exemplo do software `gcc`<sup>1</sup> - mais comumente utilizado).<sup>2</sup>

```bash
gcc [nome-do-arquivo].c -o [nome-do-executável]
```

ao fim do processo de compilação, um arquivo será criado e poderá ser executado normalmente.

```bash
./[nome-do-executável]
```

##  Tipos elementares de dados

A `linguagem C` é uma linguagem de programação fortemente tipada, o que significa que esta permite alocar na memória da máquina espaços nomeados por especificadores<sup>3</sup> de alguns tipos de dados que são fixos ao longo da execução do programa.

```c
//  aloca um espaço na memória capaz de armazenar valores do tipo
[tipo] [especificador];
```

podemos alterar o valor de um especificador por meio da instrução de atribuição.

```c
//  atribui o valor ao especificador
[especificador] = [valor];
```

podemos ter alguns problemas ao processar valores com tipos distintos do que imaginamos. Para evitar problemas com a tipagem dos dados, podemos efetuar conversões de tipo utilizando o processo de *type-casting* do valor.

```c
//  converte o valor ao valor corresponde do dado tipo
([tipo]) [valor];
```

na `linguagem C` podemos efetuar a alocação e atribuição imediata de um valor graças a um *syntatic sugar* presente na linguagem.

```c
//  aloca um espaço na memória e atribui o valor a ele
[tipo] [especificador] = [valor];
```

### Leitura e escrita de dados

Para efetuarmos leitura e escrita de dados na `linguagem C` pela entrada e saída padrão, respectivamente conhecidos por `stdin` e `stdout`, podemos utilizar as funções `scanf` e `printf` do cabeçalho `stdio.h`.

```c
//  lê a mensagem em stdin e atribui o valor ao especificador no formato placeholder
scanf("[placeholder]", &[especificador]);
```
```c
//  escreve a mensagem em stdout substituindo cada 'placeholder' pelo valor do
//  especificador correspondente no formato de placeholder
printf([texto-com-placeholders], [lista-de-especificadores]);
```

### Dados do tipo `char`

Dados alfanuméricos (caracteres presentes no teclado) podem ser atribuidos a especificadores do tipo `char`, que aloca na memória `1 byte` - usualmente são utilizadas cadeias de dados alfanuméricos, devido à sua maior utilidade. Para a leitura e escrita de dados alfanuméricos com as funções da biblioteca `stdio.h` utilizamos os especificadores de formato `%c` e `%s` como *placeholders* para um `char` e uma cadeia de caracteres, respectivamente.<sup>4</sup>

>   [**Exemplo de cadeia de caracteres**](./2.char.c)
>
>   Um exemplo simples da utilização de cadeias de dados alfanuméricos é a que se segue:
>```c
>#include <stdio.h>
>
>int main() {
>    // aloque uma cadeia de 9 caracteres para armazenar caracteres e atribua
>    // 'olá mundo' seguido de uma nova linha
>    char mensagem[10] = "olá mundo";
>    // escreva a mensagem na saída padrão
>    printf("mensagem: %s\n", mensagem);
>    return 0;
>}
>```
>
>   mensagem foi declarado com "`[11]`" ao final do especificador para declarar que mensagem possui 10 caracteres e o caractere "`\0`" que representa o fim da mensagem.

### Tipos numéricos elementares

Dados numéricos são categorizados em três tipos principais (`int`, `float` e `double`) que podem ser modificados para se tornarem apropriados a dados contextos.

Podemos operar dados numéricos segundo suas operações padão, podendo elas ser unárias (atuando num único operando) ou binárias (atuando em dois operandos). As operações unárias que atuam em dados numéricos são apenas aquelas que atuam sob o seu sinal (`+` e `-`).

```c
//  computa o valor do número com sinal igual
+[número];
//  computa o valor do número com sinal oposto
-[número];
```

operações binárias consistem nas operações aritméticas tradicionais (`+`, `-`, `*` e `/`).

```c
//  computa o valor da adição dos números
[primeiro-número] + [segundo-número];
//  computa o valor da subtração dos números
[primeiro-número] - [segundo-número];
//  computa o valor da multiplicação dos números
[primeiro-número] * [segundo-número];
//  computa o valor da divisão dos números
[primeiro-número] / [segundo-número];
```

#### números inteiros

Dados numéricos inteiros são categorizados primitivamente como sendo do tipo `int`

> um `int` aloca `4 bytes` na memória da máquina, podendo assim armazenar $2^{4 \cdot 8} = 2^{32}$ valores distintos, que podem representar números negativos, o elemento neutro e números positivos, ou seja, números inteiros entre $-2^{32} / 2 = -2^{31}$ e $+2^{32} / 2 - 1 = +2^{31} - 1$.

dados desse tipo (e suas variações) ademais às operações numéricas usuais, já apresentadas anteriormente, podem ser operados pela operação binária de módulo (`%`), também conhecida como resto da divisão.

```c
//  computa o valor do módulo dos números
[primeiro-número] % [segundo-número];
```

Para a leitura e escrita de números inteiro com as funções da biblioteca `stdio.h` utilizamos os especificadors de formato `%d` (decimal), `%b` (binário) e `%x` (hexadecimal) como placeholders para um `int`.

>   [**Exemplo de inteiros**](./3.int.c)
>
>   Um exemplo simples da utilização de dados numéricos `int` é o que se segue:
>```c
>#include <stdio.h>
>
>int main() {
>    // aloque dois inteiros que consistirão nos operandos
>    int a, b;
>    // requisite o primeiro operando
>    printf("insira o primeiro operando: ");
>    scanf("%d", &a);                // leia o valor
>    // requisite o segundo operando
>    printf("insira o segundo operando: ");
>    scanf("%d", &b);                // leia o valor
>    // escreva o resultado das operações
>    printf("%d + %d = %d\n", a, b, a + b);
>    printf("%d - %d = %d\n", a, b, a - b);
>    printf("%d * %d = %d\n", a, b, a * b);
>    printf("%d / %d = %d\n", a, b, a / b);
>    printf("%d mod %d = %d\n", a, b, a % b);
>    return 0;
>}
>```

##### dados do tipo `unsigned`

Contanto, nem sempre necessitamos levar em conta o sinal de números inteiros em nossos processos. Podemos utilizar o tipo de dado `unsigned` (*syntatic sugar* para `unsigned int`) para representar dados inteiros não assinalados. Para a leitura e escrita de dados `unsigned` com as funções da biblioteca `stdio.h` utilizamos os especificadors de formato `%u`.

> um `unsigned` aloca também `4 bytes` na memória da máquina, podendo assim armazenar $2^{4 \cdot 8} = 2^{32}$ valores distintos, que podem representar o elemento neutro e números positivos, ou seja, números inteiros entre $0$ e $+2^{32}$.

##### dados dos tipos `short` e `long`

Ademais, podemos alocar mais ou menos memória para os dados de tipo `int` utilizando `short` (aloca `2 bytes`), `long` (aloca `8 bytes`), sendo ambos *syntatic sugars* para `short int` e `long int` repectivamente. Para a leitura e escrita de dados `short` e `long` com as funções da biblioteca `stdio.h` utilizamos os especificadors de formato `%hd` (`%hb` e `%hx`) e `%ld` (`%lb` e `%lx`).

> um `short` aloca também `2 bytes` na memória da máquina, podendo assim armazenar $2^{2 \cdot 8} = 2^{16}$ valores distintos, que podem representar números negativos, o elemento neutro e números positivos, ou seja, números inteiros entre $-2^{16} / 2 = -2^{15}$ e $+2^{16} / 2 - 1 = +2^{15} - 1$.

> um `long` aloca também `8 bytes` na memória da máquina, podendo assim armazenar $2^{8 \cdot 8} = 2^{64}$ valores distintos, que podem representar números negativos, o elemento neutro e números positivos, ou seja, números inteiros entre $-2^{64} / 2 = -2^{63}$ e $+2^{64} / 2 - 1 = +2^{63} - 1$.


#### números com ponto flutuante

Dados numéricos reais (que possuem dizima) são categorizados primitivamente como sendo do tipo `float`

> um `float` aloca `4 bytes = 32 bits` na memória da máquina, dentre estes, o primeiro `bit` é utilizado para denotar o sinal $\pm$ (`0` se positivo ou `1` se negativo), os próximos são utilizados para representar o valor absoluto em notação científica ($m \times 10^{e}$), sendo os primeiros `8 bits` para representar o expoente (podendo assim representar expoentes entre $-2^8 / 2 = -128$ e $+2^8 / 2 - 1 = +127$) e os demais `23 bits` para a mantissa (tendo assim ${log}_{10}(2^{23}) \approx 6$ digitos de precisão).

Para a leitura e escrita de números reais com as funções da biblioteca `stdio.h` utilizamos os especificadors de formato `%f` (representação em ponto flutuante) e `%g` ou `%e` (representação científica) como placeholders para um `float`.

>   [**Exemplo de números com ponto flutuante**](./4.float.c)
>
>   Um exemplo simples da utilização de dados numéricos `float` é o que se segue:
>```c
>#include <stdio.h>
>
>int main() {
>    // aloque um número real que consistirá no raio do círculo
>    float raio;
>    // aloque um número real para armazenar o valor de pi
>    float pi = 3.1415;
>    // requisite o valor do raio
>    printf("insira o valor do raio: ");
>    scanf("%f", &raio);             // leia o valor
>    // informe o valor da circunferência
>    printf("circunferência = %f\n", 2. * pi * raio);
>    return 0;
>}
>```

##### dados dos tipos `double` e `long double`

Ademais, podemos alocar mais memória para dados numéricos de modo a obter mais casas de precisão, utilizando `double` (aloca `8 bytes`) e `long double` (aloca `16 bytes`). Para a leitura e escrita de números reais com as funções da biblioteca `stdio.h` utilizamos os especificadors de formato `%lf` para `double` e `%llf` para `long double`.

> um `double` aloca `8 bytes = 64 bits` na memória da máquina, dentre estes, o primeiro `bit` é utilizado para denotar o sinal $\pm$ (`0` se positivo ou `1` se negativo), os próximos são utilizados para representar o valor absoluto em notação científica ($m \times 10^{e}$), sendo os primeiros `11 bits` para representar o expoente (podendo assim representar expoentes entre $-2^{11} / 2 = -1024$ e $+2^{11} / 2 - 1 = +1023$) e os demais `52 bits` para a mantissa (tendo assim ${log}_{10}(2^{52}) \approx 15$ digitos de precisão).

> um `long double` aloca `16 bytes = 128 bits` na memória da máquina, dentre estes, o primeiro `bit` é utilizado para denotar o sinal $\pm$ (`0` se positivo ou `1` se negativo), os próximos são utilizados para representar o valor absoluto em notação científica ($m \times 10^{e}$), sendo os primeiros `15 bits` para representar o expoente (podendo assim representar expoentes entre $-2^{15} / 2 = -16384$ e $+2^{15} / 2 - 1 = +16383$) e os demais `112 bits` para a mantissa (tendo assim ${log}_{10}(2^{112}) \approx 18$ digitos de precisão).

##### funções matemáticas elementares do cabeçalho `math.h`

Em adição às operações aritméticas tradicionais, podemos utilizar funções matemáticas elementares sobre números com ponto flutuante, que já são previamente implementadas no cabeçalho `math.h` da `linguagem C`. As funções matemáticas implementadas no cabeçalho `math.h` são as que se seguem:

> `pow(x, y)`
> 
> computa `x`<sup>`y`</sup>.

> `round(x)`
> 
> computa o inteiro mais próximo de `x`.

> `ceil(x)`
> 
> computa o menor inteiro que supera `x`.

> `floor(x)`
> 
> computa o maior inteiro que não supera `x`.

> `fabs(x)`
> 
> computa o valor absoluto de `x`.

> `sqrt(x)`
> 
> computa a raíz quadrada de `x`.

> `exp(x)`
> 
> computa a exponencial de `x` na base $e$.

> `log(x)`
> 
> computa o logaritmo de `x` na base $e$.

> `log10(x)`
> 
> computa o logaritmo de `x` na base $10$.

> `sin(x)`
>
> computa o seno de `x`.

> `cos(x)`
>
> computa o cosseno de `x`.

> `tan(x)`
>
> computa a tangente de `x`.

> `asin(x)`
>
> computa o arco cujo seno é `x`.

> `acos(x)`
>
> computa o arco cujo cosseno é `x`.

> `atan(x)`
>
> computa o arco cuja tangente é `x`.

> `atan2(x, y)`
>
> computa o arco cuja tangente é `x` / `y` baseado no sinal de ambos.

> `sinh(x)`
>
> computa o seno hiperbólico de `x`.

> `cosh(x)`
>
> computa o cosseno hiperbólico de `x`.

> `tanh(x)`
>
> computa a tangente hiperbólica de `x`.

Diferente das demais bibliotecas padrão em `C`, ao utilizá-la num código-fonte, precisa-se de uma *flag* adicional ao efetuar a compilação. 

```bash
gcc [nome-do-arquivo].c -o [nome-do-executável] -lm
```

### Constantes

Podemos tornarmos um especificador constante ao longo da execução de um programa implementado na `linguagem C` podemos utilizar o modificador `const` na declaração (seguido da atribuição do valor da constante),

```c
//  cria um especificador que não pode ter seu valor modificado
const [tipo] [especificador] = [valor];
```

de modo que, o compilador não permite a criação de um arquivo executável caso alguma instução no programa atribua um novo valor ao especificador.

>   [**Exemplo de especificador constante**](./5.const.c)
>
>   Um exemplo elementar de erro de compilação devido ao modificador const é o que se segue:
>
>```c
>int main() {
>    // aloque um double especificado como 'pi' com valor fixo de 3.14
>    const double pi = 3.14;
>    // ...
>    pi = 3.1415;                    // atribua o valor 3.14 a 'pi'
>    // ...
>   return 0;
>}
>```
>   ao tentar compilar o código-fonte num programa executável, o compilador emite:
>
> > <span style="color: red"> **error:** </span> assignment of read-only variable '**pi**'
>
>   impedindo a criação de um programa executável.

de modo geral, não há efeitos de atribuir o modificador `const`, contudo é uma boa prática modificar especificadores que desejam-se fixos, para evitar comportamentos indesejados.

---

**[1]** para instalar o software `gcc` no windows é recomendado instalar o software `Windows Subsystem for Linux` (`WSL`).

**[2]** denotaremos, nesta e nas demais notas, elementos obrigatórios da síntaxe dos comandos como `[`*`placeholder`*`]` e elementos optativos como `<`*`placeholder`*`>`.

**[3]** nem todo especificador (nome de variável) é válido na `linguagem C`, apenas aqueles iniciados por letras (`a ... z` ou `A ... Z`) ou *underscore* (`_`) e seguidos por letras, *underscores* ou números.

**[4]** para o caso da leitura de cadeias de caractere utilizando o cabeçalho `stdio.h` não se precede o especificador por "`&`" .

---

<div style="text-align: right;">

[voltar à página principal](../README.md)

</div>
