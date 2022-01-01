#include "workplace.h"
#include <string>
#include <map>

mtm::Workplace::Workplace(long id, std::string workplaceName, long workerSalary, long managerSalary) : id(id),
                                                                                                       name(workplaceName),
                                                                                                       worker_salary(workerSalary),
                                                                                                       manager_salary(managerSalary)
{
}

std::string mtm::Workplace::getName() const
{
    return name;
}
long mtm::Workplace::getId() const
{
    return id;
}

long mtm::Workplace::getWorkerSalary() const
{
    return worker_salary;
}

long mtm::Workplace::getManagerSalary() const
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
    std::map<long, Manager *>::iterator iterator = managers.find(managerId);
    if (iterator == managers.end())
        throw; // TODO: ManagerIsNotHired exception

    (iterator->second)->removeEmployee(employeeId);
}

void mtm::Workplace::hireManager(Manager *manager)
{
    if (!managers.insert({manager->getId(), manager}).second)
        throw; // TODO: ManagerAlreadyHired exception
}

void mtm::Workplace::fireManager(long managerId)
{
    if (managers.erase(managerId) == 0)
        throw; // TODO: ManagerNotHired excception
}

std::ostream &mtm::operator<<(std::ostream &os, const mtm::Workplace &workplace)
{
    os << "Workplace name - " << workplace.getName();

    if (!workplace.managers.empty())
        os << " Groups:";

    os << std::endl;

    for (const std::pair<long, Manager *> &manager_pair : workplace.managers)
    {
        manager_pair.second->printLong(os);
    }

    return os;
}