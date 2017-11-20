/*
 * Copyright 2016-2017 Flatiron Institute, Simons Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include <QObject>
#include <QList>
#include "icomponent.h"

class ComponentManager : public QObject {
    Q_OBJECT
public:
    ComponentManager(QObject* parent = 0);
    ~ComponentManager();
    void addComponent(IComponent* c);
    void loadComponents();
    void unloadComponents();
    QList<IComponent*> loadedComponents() const;

protected:
    QList<IComponent*> resolveDependencies() const;

private:
    QList<IComponent*> m_components;
    QList<IComponent*> m_loaded;
};

#endif // COMPONENTMANAGER_H
