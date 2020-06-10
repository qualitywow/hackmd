# Convex optimization
https://www.youtube.com/watch?v=qF0aDJfEa4Y

https://www.youtube.com/watch?v=Sre_s1dFQmE

**最重要/有用的屬性**:
- 兩個不相交的convex set，可用一條直線分開彼此
- 一個non-convex、一個convex無法用直線完全分開

convex set is defined from a convex function
if there is a function $f$, 
$f'$ can tell it's increasing/decreasing
$f''$ can tell it's upward/downward

a convex function $f(x)$, the minus of $f(x)$ will be convex, and called concave function.

要是一個function中同時有convex part和concave part，它就不會是convex function。  
只有 $f''(x) \geq 0$才會是個convex function

對多變數函數$f(x,y) = x^2 + xy + y^2$做二階導數測試，得到此函數的Hessian matrix
\begin{bmatrix}
\frac{\partial^2f}{\partial x^2} & \frac{\partial^2f}{\partial x \partial y} \\
\frac{\partial^2f}{\partial y \partial x} & \frac{\partial^2f}{\partial y^2} 
\end{bmatrix} =
\begin{bmatrix}
2 & 1 \\
1 & 2
\end{bmatrix}

$f(x_1, x_2, ... x_n)$

$\frac{\partial^2f}{\partial x_i \partial x_j} = HessianMatrix[i, j]$
