% Задаем функцию и интервал
f = @(x) sin(x)./x;
a = 1;
b = 10;
valx = linspace(a, b, 100);
y_o = f(valx);
for i = 2:10
n = i;% Выбираем равноотстоящие узлы на отрезке [1, 10]
n
x = linspace(a, b, n);
y = f(x);
% многочлен Лагранжа
valx = linspace(a, b, 100);
valy = arrayfun(@(xv) lagrange(x, y, xv), valx);
% Используем функцию polyfit для сравнения с найденным многочленом Лагранжа
p = polyfit(x, y, n-1);
y_polyfit = polyval(p, valx);
% Сравниваем результаты
figure('Position', [0, 0, 400, 400]);
plot(valx, valy, valx, y_polyfit, x, y, 'ko', valx, y_o);
legend({'Лагранж', 'Polyfit', 'Узлы интерполяции', 'sin(x)/x'}, 'Location', 'best');
xlabel('x');
ylabel('y');
title(' Лагранжа и polyfit n');
end



% Исходная функция и интервал
f = @(x) sin(x)./x;
a = 1;
b = 10;

% Количество узлов интерполяции
n = 5;

% Создание равноотстоящих узлов интерполяции
x = linspace(a, b, n);
y = f(x);

% Построение интерполяционного многочлена Ньютона
coeff = newton_coeff(x, y);
newton = @(t) newton_evaluate(coeff, x, t);

t = linspace(a, b, 1000);% Создание вектора для графика

% Проверка правильности с помощью polyfit
p = polyfit(x, y, n-1);

% Отображение графиков
figure;
figure('Position', [0, 0, 400, 400]);
plot(t, newton(t), t, polyval(p, t), x, y, 'ko', t, f(t));
legend({'Ньютон', 'Polyfit', 'Узлы интерполяции', 'sin(x)/x'}, 'Location', 'best');
xlabel('x');
ylabel('y');
title(' Ньютон и polyfit n');

data = [-2.00 1.50;
        -1.30 2.40;
        -0.13 3.90;
        0.52 5.70;
        0.79 5.70;
        1.60 3.80;
        3.10 2.30;
        3.60 1.50;
        5.30 0.98;
        5.10 0.70];

% Разделение данных на координаты x и y
x_data = data(:, 1);
y_data = data(:, 2);

% Функция для аппроксимации
f = @(x, b) 1 ./ (b(1) + b(2) .* x + b(3) .* (x.^2));

% Метод наименьших квадратов для аппроксимации
A = [ones(size(x_data)), x_data, x_data.^2]
b = A \ (1 ./ y_data); % коэффициенты аппроксимирующей функции

% Создание вектора для графика
x_fit = linspace(min(x_data), max(x_data), 100);
y_fit = f(x_fit, b);

% Отображение аппроксимирующей функции и табличных данных на графике
figure;
plot(x_data, y_data, 'bo', x_fit, y_fit);
title('Аппроксимация данных');
xlabel('x');
ylabel('y');
legend('Табличные данные', 'Аппроксимация');
grid on;

% Исходные и предсказанные значения
y_true = y_data; % истинные значения
y_pred = f(x_data, b); % предсказанные значения с использованием аппроксимирующей функции

% Вычисление RMSE
N = length(y_true);
RMSE = sqrt(sum((y_true - y_pred).^2) / N);
RMSE

function L = lagrange(x, y, x_val)
    n = length(x); % число узлов интерполяции
    L = 0;
    for i = 1:n
        P = 1;
        for j = 1:n
            if i ~= j
                % полином Лагранжа
                P = P * (x_val - x(j)) / (x(i) - x(j));
            end
        end
        % считаем сумму
        L = L + y(i) * P;
    end
end



 % Функция для вычисления коэффициентов интерполяционного многочлена Ньютона
function coeffs = newton_coeff(x, y) 
    n = length(x); % Получаем число узлов интерполяции
    coeffs = zeros(1, n);
    for k = 1:n 
        coeffs(k) = y(k); % Присваиваем текущий коэффициенту значение функции в узле
        for j = n:-1:k+1 % Цикл для вычисления разделенных разностей
            % Вычисляем разделенные разности и обновляем значения функции
            y(j) = (y(j) - y(j-1)) / (x(j) - x(j-k));
        end
    end
end

% Функция для вычисления значения интерполяционного многочлена Ньютона в заданных точках
function val = newton_evaluate(coeffs, x, t)
    n = length(coeffs);
    val = coeffs(n);
    for k = n-1:-1:1 % обратном порядке
        val = val .* (t - x(k)) + coeffs(k);
    end
end