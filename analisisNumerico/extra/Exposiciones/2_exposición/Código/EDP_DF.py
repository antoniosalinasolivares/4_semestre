import math

#u"(x)=-pi*picos(pix)   0<x<1  u(0)=1  u(1)=-1

def LadoDerecho(x):#Lado derecho de la ecuacion diferencial parcial
    return -math.pi * math.pi * math.cos(math.pi * x)

def GaussSeidel(A, b, N, iter):#Resuelve Ax=b usando el metodo GaussSeidel
    sum = 0
    x = [0] * N
    for m in range(iter):
        for i in range(N):
            sum = 0.0
            for j in range(N):
                if  i == j:
                    continue
                sum += A[i][j] * x[j]
            x[i] = (1.0 / A[i][i]) * (b[i] - sum)
    return x



# Ecuación Diferencial Parcial

xi = 0.0                  # Inicio del diminio
xf = 1.0                  # Fin del dominio
vi = 1.0                  # Valor en la frontera xi
vf = -1.0                 # Valor en la frontera xf
n = 11                    # Particion
N = n-2                   # Incognitas
h = (xf - xi) / (n - 1);  # Incremento en la malla


# Declaracion de la matriz A y los vectores b y x
A = []                   # Matriz A
for i in range(N):
	A.append([0]*N)
b = [0] * N              # Vector b
x = [0] * N              # Vector x

# Diferencias Finitas
R = 1 / (h * h)
P = -2 / (h * h)
Q = 1 / (h * h)

# Primer renglon de la matriz A y vector b
A[0][0] = P
A[0][1] = Q
b[0] = LadoDerecho(xi) - vi * R
print(b)
# Renglones intermedios de la matriz A y vector b
for i in range(1,N-1):
	A[i][i - 1] = R
	A[i][i] = P
	A[i][i + 1] = Q
	b[i] = LadoDerecho(xi + h * (i + 1))
    
# Renglon final de la matriz A y vector b
A[N - 1][N - 2] = R
A[N - 1][N - 1] = P
b[N - 1] = LadoDerecho(xi + h * N - 2) - vf * Q

# Resuelve por el metodo Gauss-Seidel
for i in range(N):
    for j in range(N):
        print(' ', A[i][j],end='')
    print("")

print("Valores de b")
print(b)
x = GaussSeidel(A, b, N, N*7)

print("Valores de X")
print(x)
# Solucion
print("Solución")
print("Xi   Vi")
print(xi, vi)
for i in range(N):
    print(xi + h * (i + 1), x[i])
print(xf, vf)


