% Задаем функцию и интервал
f = @(x) sin(x.^2);
a = -3;
b = 0;
x_val = linspace(a, b, 100);
y_o = f(x_val);
for i = 3:9
% Выбираем равноотстоящие узлы на отрезке [-3, 0]
n = i; % Количество узлов
n
x = linspace(a, b, n);
y = f(x);
% Вычисляем интерполяционный многочлен Лагранжа для заданных узлов
x_val = linspace(a, b, 100);
y_val = arrayfun(@(xv) lagrange_interpolation(x, y, xv), x_val);
% Используем функцию polyfit для сравнения с найденным многочленом Лагранжа
p = polyfit(x, y, n-1);
y_polyfit = polyval(p, x_val);
% Сравниваем результаты
figure('Position', [0, 0, 400, 400]);
plot(x_val, y_val, 'b-', x_val, y_polyfit, 'r--', x, y, 'ko', x_val, y_o, 'g--');
legend({'Лагранж', 'Polyfit', 'Узлы интерполяции', 'sin(x^2)'}, 'Location', 'best');
xlabel('x');
ylabel('y');
title(' Лагранжа и polyfit n');
end



% Исходная функция и интервал
f = @(x) sin(x.^2);
a = -3;
b = 0;

% Количество узлов интерполяции
n = 3;

% Создание равноотстоящих узлов интерполяции
x = linspace(a, b, n);
y = f(x);

% Построение интерполяционного многочлена Ньютона
coefficients = newton_coefficients(x, y);
newton_poly = @(t) newton_evaluate(coefficients, x, t);

% Создание вектора для графика
t = linspace(a, b, 1000);

% Проверка правильности с помощью polyfit
p = polyfit(x, y, n-1);

% Отображение графиков
figure;
figure('Position', [0, 0, 400, 400]);
plot(t, newton_poly(t), 'b-', t, polyval(p, t), 'r--', x, y, 'ko', t, f(t), 'g--');
legend({'Ньютон', 'Polyfit', 'Узлы интерполяции', 'sin(x^2)'}, 'Location', 'best');
xlabel('x');
ylabel('y');
title(' Ньютон и polyfit n');

 function coeffs = newton_coefficients(x, y) 
    n = length(x);
    coeffs = zeros(1, n);
    for k = 1:n
        coeffs(k) = y(k);
        for j = n:-1:k+1
            y(j) = (y(j) - y(j-1)) / (x(j) - x(j-k));
        end
    end
end

function val = newton_evaluate(coeffs, x, t)
    n = length(coeffs);
    val = coeffs(n);
    for k = n-1:-1:1
        val = val .* (t - x(k)) + coeffs(k);
    end
end







function L = lagrange_interpolation(x, y, x_val) % 3. Функция для вычисления интерполяционного многочлена Лагранжа
    n = length(x);
    L = 0;
    for i = 1:n
        P = 1;
        for j = 1:n
            if i ~= j
                P = P * (x_val - x(j)) / (x(i) - x(j));
            end
        end
        L = L + y(i) * P;
    end
 end
