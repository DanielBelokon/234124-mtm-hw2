#include "workplace.h"
#include <string>
#include <map>

mtm::Workplace::Workplace(long id, std::string workplaceName, long workerSalary, long managerSalary) : id(id),
                                                                                                       name(workplaceName),
                                                                                                       worker_salary(workerSalary),
                                                                                                       manager_salary(managerSalary)
{
}

std::string mtm::Workplace::getName()
{
    return name;
}
long mtm::Workplace::getId()
{
    return id;
}

long mtm::Workplace::getWorkerSalary()
{
    return worker_salary;
}

long mtm::Workplace::getManagerSalary()
{
    return manager_salary;
}

template <class Condition>
void mtm::Workplace::hireEmployee(Condition isHirable, Employee *employee, int managerId)
{
    if (!isHirable(employee))
        throw; // TODO: EmployeeNotSelected exception
}

void mtm::Workplace::fireEmployee(long employeeId, long managerId)
{
    Manager *manager = managers.find(managerId)->second;
    if (manager == NULL)
        throw; // TODO: ManagerIsNotHired exception

    manager->removeEmployee(employeeId);
}

void mtm::Workplace::hireManager(Manager *manager)
{
}

void mtm::Workplace::fireManager(long managerId)
{
}