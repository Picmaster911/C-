#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H
#include <QLabel>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QPushButton>

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalculatorWindow(QWidget *parent = nullptr);
    ~CalculatorWindow();

private slots:
    void onButtonClicked();

private:
    QWidget* m_central = nullptr;
    QLabel* m_display = nullptr;
    QVBoxLayout* m_rootLayout = nullptr;
    QGridLayout* m_grid = nullptr;
    void init ();
    double m_acc = 0.0;
    QString m_pendingOp; // "+", "-", "*", "/"
    bool m_waitingForNewNumber = true;
    bool m_error = false;

    double currentValue() const;
    void setDisplayNumber(double v);
    void clearAll();
    void applyPendingOperation(double rhs);
    void inputDigit(const QString& d);
    void inputDot();
    void inputOp(const QString& op);
    void inputEquals();
    void inputBackspace();
    QPushButton* makeButton(const QString& text, const QString& objName);
};
#endif // CALCULATORWINDOW_H
