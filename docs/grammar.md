$$
\begin{align}
    [\text{prog}] &\to [\text{stmt}]^*\\
    [\text{stmt}] &\to \begin{cases}
                    periodt([\text{expr}]);\\
                    itsgiving \; \text{ident} = [\text{expr}];
                    \end{cases}\\
    [\text{expr}] &\to \text{intlit}
\end{align}
$$
